package main

import (
    "fmt"
    "time"
	"sync"
)

var mutex sync.Mutex

func compute(wg *sync.WaitGroup, value int) {
	mutex.Lock()
    for i := 0; i < value; i++ {
        time.Sleep(time.Second)
        fmt.Println(i)
    }
	mutex.Unlock()
	wg.Done()
}

func main() {

	// Declare a anonymous function as goroutine. 
	go func() {
        fmt.Println("Executing my Concurrent anonymous function")
    }()

	// Named function declared as goroutine.  
	// Serialize go routine using waitgroup and mutex. 
	var wg sync.WaitGroup
	wg.Add(2)

	go compute(&wg, 10)   //  Wait group being used for named function
    go compute(&wg, 10)

	// Wait group added for anynymous function. 
	go func() {
        fmt.Println("Inside my goroutine")
        waitgroup.Done()
    }()

	wg.wait()

    var input string
    fmt.Scanln(&input)
}
