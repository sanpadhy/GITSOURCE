
/*
Given an integer N, construct all possible binary search trees with N nodes.
*/

package main

import (
	"fmt"
)

func main() {
	fmt.Println(getPossibleBinaryTree(3))
}

func getPossibleBinaryTree(N int) int {
	T := make([]int, N+1)
    T[0] = 1
    T[1] = 1

	var i int

	for i = 2; i <= N; i++ {
		for j := 0; j < i; j++ {
            T[i] += T[j] * T[i-j-1]
		}
	}
    return T[i-1]
}
