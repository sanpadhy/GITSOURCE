package main

import (
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	c := make(chan int)
	n := 10
	wg.Add(1)
	go func(c chan int) {
		sum := 0
		v := <-c
		go func() {
			for {
				fmt.Println("hello")
			}
		}()

		for i := 0; i < v; i++ {
			sum += i
		}
		c <- sum
		wg.Done()
		err := "hehkk"
		panic(err)
		close(c)
	}(c)
	c <-n

	wg.Wait()
	fmt.Println(<-c)
	
}
