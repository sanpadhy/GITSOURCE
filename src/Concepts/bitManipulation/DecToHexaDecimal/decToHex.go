// decToHex
package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

var wg sync.WaitGroup

func init() {
	runtime.GOMAXPROCS(runtime.NumCPU())
}

func foo() {
	fmt.Println("Hello")
	//	wg.Done()
}

func bar() {
	fmt.Println("world")
	//	wg.Done()
}

func main() {
	//	wg.Add(2)
	go foo()
	time.Sleep(2)
	go bar()
	time.Sleep(2)
	//	wg.Wait()
}
