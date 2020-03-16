/*
Describe an algorithm to compute the longest increasing subsequence of an array of numbers in O(n log n) time.
*/


package main

import (
	"fmt"
)

func longestIncreasingSubs(arr []int) []int {
	var start int = 0
	var end int = 0
	var longest = []int{arr[0]}

	for i := 1; i < len(arr); i++ {
		if arr[i] < arr[i-1] {
			start = i
			fmt.Println(start)
		}
		end = i+1

		if len(arr[start:end]) > len(longest) {
			longest = append(longest, arr[i])
			fmt.Println(longest)
		}
	}

	return longest
}

func main() {
	var arr = []int{1, 2, 3, 5, 4}

	fmt.Println(longestIncreasingSubs(arr))
}
