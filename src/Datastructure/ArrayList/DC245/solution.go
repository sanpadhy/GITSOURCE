/*
# You are given an array of integers, where each element represents the maximum number of steps that
# can be jumped going forward from that element. Write a function to return the minimum number of jumps
# you must take in order to get from the start to the end of the array.

# For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution involves
# jumping from 6 to 5, and then from 5 to 9.
*/

package main

import (
	"fmt"
)

func getMinimalStepsToEnd(arr []int) int {
	var lenA = len(arr)
	result := make([]int, lenA)
	var i int
	for i= 1; i < lenA; i++ {
		for j := 0; j < i; j++ {
			if j + arr[j] >= i {                 // <<<<<<  
				if (result[j] + 1 < result[i]) || (result[i] == 0) {
					result[i] = result[j]+1

				}
			}

		}
	}
	return result[i-1]
}

func main() {
	var arr = []int{6, 2, 4, 0, 5, 1, 1, 4, 2, 9}

	fmt.Println(getMinimalStepsToEnd(arr))
}
