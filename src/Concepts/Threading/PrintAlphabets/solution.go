package main

import (
	"fmt"
	"sync"
	)

func main() {
	var count int
	var wg sync.WaitGroup
	var mx sync.Mutex
	count = 0
	for n := 0; n < 26; n++ {
		wg.Add(1)
		go func(num int) {
			defer wg.Done()
			loop:
				mx.Lock()
				if count == num - 'a' {
					fmt.Println("%c", string(num))
					count += 1
					mx.Unlock()
					return
				}
				mx.Unlock()
				goto loop
		}('a' + n)
	}
	wg.Wait()
}
