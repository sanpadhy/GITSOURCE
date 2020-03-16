/*
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees. For example, 16891 is strobogrammatic.

Create a program that finds all strobogrammatic numbers with N digits.
*/

package main

import (
	"fmt"
)

func getStrobGramNumb(n int) []int {
	if n == 0 {
		return [""]
	}

	if n = 1 {
		return ["0", "1", "8"]
	}

	stobNumbers = getStrobGramNumb(n - 2)

	result := 
	
}


func main() {



}
