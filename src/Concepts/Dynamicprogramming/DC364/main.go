/* incomplete. */


package main

import (
	"fmt"
)

func findLongestIncrSubs(arr []int) int {
	start := 0
	end := 0
	var longest []int;
	startChar := arr[0]
	longest = append(longest, startChar)

	for i := 1; i < len(arr); i++ {
		if arr[i] < arr[i-1] {
			start = i-1
			fmt.Println(start)
		}
		end = i
		fmt.Println(end)

		if end-start > len(longest) {
			longest = append(longest, arr[i])
		}
	}

	return len(longest)
}


func main() {
	arr := []int{1, 2, 3, 5, 4}
	len := findLongestIncrSubs(arr)
	fmt.Println(len)
}


