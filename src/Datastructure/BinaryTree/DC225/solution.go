package main

import (
	"fmt"
)

func findLastExecution(n int, k int) int {
	var prisoners []int
	for i:=0; i < n; i++ {
		prisoners = append(prisoners, i+1)	
	}
	next_prisoner_index := 0
	last_prisoner := 0

	for prisoners {
		next_prisoner_index = (next_prisoner_index)+k-1/len(prisoners)
		last_prisoner = prisoners[next_prisoner_index]

		prisoners = prisoners[:next_prisoner_index]+prisoners[next_prisoner_index+1:]
	}

	return last_prisoner
}

func main() {
	fmt.Println(findLastExecution(5, 2))
	
}
