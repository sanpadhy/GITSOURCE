package main

import (
	"fmt"
)

func getThirdHishest(arr []int) int {
	var a = arr[0]
	var b = 0
	var c = 0

	for i := 1; i < len(arr); i++ {
		if  arr[i] > a {
			c = b
			b = a
			a = arr[i]
		} else {
			if arr[i] > b {
				c = b
				b = arr[i]
			} else {
				if arr[i] > c {
					c = arr[i]
				}
			}

		}
	}

	return c
}

func main() {
	var arr = []int{9, 8, 5, 7, 6, 10}

	fmt.Println(getThirdHishest(arr))
}


