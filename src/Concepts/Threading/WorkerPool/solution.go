/* Worker pool with Goroutines. 
*/

package main
import (
	"fmt"
	"time"
	)

func worker(id int, jobs <-chan int, results chan<- int) {
	fmt.Println(jobs)
    for j := range jobs {
        fmt.Println("worker", id, "started  job", j)
        time.Sleep(time.Second)
        fmt.Println("worker", id, "finished job", j)
        results <- j * 2
    }
}

func main() {
	const numJobs = 5
	jobs := make(chan int, numJobs)
	results := make(chan int, numJobs)

	for w := 1; w <= 3; w++ {
		go worker(w, jobs, results)
	}

	for i := 0; i < numJobs; i++ {
		jobs <- i
	}

	for i := 0; i < numJobs; i++ {
		fmt.Println(<-results)
	}
}

