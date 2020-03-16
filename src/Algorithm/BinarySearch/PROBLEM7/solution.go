package main

import (
	"fmt"
)

func binarySearch(arr []int, v int) int {
	var start = 0
	var end = len(arr)-1

	for start < end {
		mid := (start + end)/2

		if arr[mid] == v {
			return mid
		} else if v < arr[mid] {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	return -1
}

func main() {
	var xf = []int{13, 24, 35, 46, 57, 59, 70}
	fmt.Println(binarySearch(xf, 159))
}
