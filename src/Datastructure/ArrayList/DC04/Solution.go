/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

package main

import (
	"fmt"
)

func sortAnArray(arr []int, start int, end int) []int {
		i := start
		j := end

		var mid int

		for i < j {
			mid = (i+j)/2

			for arr[i] < arr[mid] {
				i++
			}
			for arr[j] > arr[mid] {
				j--
			}

			if i < j {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}

		sortAndArray(arr, start, mid-1)
		sortAndArray(arr, mid+1, end)
}

func findFirstPositive(arr []int) int {
	sortedArr = sortAnArray(arr, 0, len(arr))

	for i, _ := range arr {
		if arr[i] <= 0 {
			continue
		} else {
			if(arr[i] != 1) {
				return 1
			}

			if arr[i] != arr[i-1]+1 {
				return arr[i-1]+1
			}
		}


	}

}

func main() {
	var arr = []int{3, 4, -1, 1}

	print(findFirstPositive(arr))
}

