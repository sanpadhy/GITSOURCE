/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

package main

import (
	"fmt"
)

func sortnum(arr []int) []int {
	var i int
	var j int
	for i = 0, j = len(arr); i < j; i++, j-- {
		if arr[i] > arr[j] {
			arr[i], arr[j] = arr[j], arr[i]
		}
	}

	fmt.Println(arr)
	return arr
}


func longestConsecutive(arr []int) []int {
	fmt.Println(sortnum(arr))
	return arr
}

func main() {
	arr = []int{100, 4, 200, 1, 3, 2}
	fmt.Println(longestConsecutive(arr))
}
