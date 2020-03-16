// zarandosecond

package main

import (
	"fmt"
)

func Solution(A []int) int {
	dmap := make(map[int]bool)
	largest := 0

	for _, v := range A {
		dmap[v] = false
	}

	for _, v := range A {
		if v < 0 && v < largest {
			if _, ok := dmap[-v]; ok {
				largest = v
			}
		}
	}

	if largest < 0 {
		return -largest
	}

	return largest
}

func main() {
	fmt.Println("Hello World!")
}
