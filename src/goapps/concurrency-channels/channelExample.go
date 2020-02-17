package main

import (
    "fmt"
    "math/rand"
    "sync"
)


func CalculateValue(wg *sync.WaitGroup, values chan int) {
	value := rand.Intn(10)
	fmt.Println("Calculated Random Value: {}", value)
	values <- value
	wg.Done()
}

func main() {
	fmt.Println("Go Channel Tutorial")

	var wg sync.WaitGroup

	values := make(chan int, 2)
	defer close(values)
	wg.Add(2)

	go CalculateValue(&wg, values)
	go CalculateValue(&wg, values)

	wg.Wait()

	value := <-values
	fmt.Println(value)
}
