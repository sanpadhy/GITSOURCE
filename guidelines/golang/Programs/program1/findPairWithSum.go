package main

import (
	"fmt"
)


func getPairs(arr []int, sum int) (bool, int, int) {
	findPair := make([]int, 6)
	for _, var := range(arr) {
		if res := func(var int) {
			for _, v := range(findPair) {
				if v == var {
					return true
				}
			}
			return false
		}(); res = true {
			return (true, var, sum-var)
		}

		findPair = append(findPair, sum-var)
	}

	return (false, -1, -1)
}

func main() {
	res, var1, var2 := getPair([10, 15, 3, 7], 17)

	if res == true{
		fmt.Println("The pair %d: %d present in the list.", var1, var2)
		return;
	}

	fmt. Println("Failed to get the pair.")
	return
}

