/* Linear search method. */

package main

import (
	"fmt"
)

func linearSearch(xf []int, v int) int {
	if len(xf) == 0 {
		fmt.Println("Insuficient array.")
		return -1
	}

	for i := 0; i < len(xf); i++ {
		if xf[i] == v {
			return i
		}
	}

	return -1
}

func main() {
	var xf = []int{23, 65, 2, 56, 14}

	result := linearSearch(xf, 14)

	fmt.Println("%d", result)
}
