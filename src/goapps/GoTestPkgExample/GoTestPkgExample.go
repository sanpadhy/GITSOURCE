// GoTestPkgExample
package main

import (
	"fmt"
)

func Sum(vs ...int) int {
	return sumOfNumbers(vs)
}

func sumOfNumbers(vs []int) int {
	if len(vs) == 0 {
		return 0
	}

	return sumOfNumbers(vs[1:]) + vs[0]
}

/*
func main() {
	fmt.Println("Hello")
}
*/
