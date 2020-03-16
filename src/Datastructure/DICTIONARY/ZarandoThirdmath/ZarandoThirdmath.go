// ZarandoThirdmath
package main

import (
	"fmt"
)

func Solution(X []int, Y []int) int {
	max := 1
	dmap := make(map[string]int)

	for i := 0; i < len(X); i++ {
		st := fmt.Sprintf("%.2f", float32(X[i])/float32(Y[i]))
		if _, ok := dmap[st]; ok {
			dmap[st] += 1
		} else {
			dmap[st] = 1
		}
	}

	for _, V := range dmap {
		if V > max {
			max = V
		}
	}

	return max
}

func main() {

}
