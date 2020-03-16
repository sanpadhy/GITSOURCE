/* 
Given a list of numbers, return whether any two sums to k. For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

package main

import (
	"fmt"
)

func isPresent(arr []int, v int) bool {
	for _, vr := range arr {
		if(vr == v) {
			return true
		}
	}

	return false
}

func findPairWithSum(arr []int, sum int) bool {
	var pair []int

	if len(arr) == 0 || sum == 0 {
		return true
	}

	for _, v := range arr {
		if isPresent(pair, v) {
			return true
		}
		pair = append(pair, sum - v)
	}

	return false;
}

func main() {
	var arr = []int{10, 15, 3, 7}

	fmt.Println(findPairWithSum(arr, 18))

}
