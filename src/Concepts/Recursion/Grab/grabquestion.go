// grabquestion
package main

import (
	"fmt"
)

func sum(C []int, n int) int {

	sum := 0

	for i := 0; i < n; i++ {
		sum += C[i]
	}

	fmt.Println(sum)

	return sum
}

func get_encoded_streams(C []int, M [][]int, U int, L int, col int) bool {
	if len(C) == 0 {
		return (U == 0 && L == 0)
	}

	if col == len(C) {
		return true
	}

	sum1 := U + L
	fmt.Println("%d", sum1)
	/*
		if sum(C, len(C)) != sum1 {
			return false
		}
	*/
	if C[col] == 2 {
		M[col][0], M[col][1] = 1, 1
		return get_encoded_streams(C, M, U-1, L-1, col+1)
	}

	if C[col] == 0 {
		M[col][0], M[col][1] = 0, 0
		return get_encoded_streams(C, M, U, L, col+1)
	} else {
		M[0][col] = 1
		value := get_encoded_streams(C, M, U-1, L, col+1)

		if value == false {
			M[0][col] = 0
			M[1][col] = 1
		}

		return get_encoded_streams(C, M, U, L-1, col+1)
	}
}

func main() {

	C := []int{2, 0, 1, 1}

	U := 2
	L := 2

	n := len(C)

	ma := make([][]int, 2)
	/*
		for i := 0; i < len(ma); i++ {
			ma[i] = make([]int, len(C))
		}
	*/

	for i := 0; i < len(ma); i++ {
		ma[i] = make([]int, n)
	}

	if get_encoded_streams(C, ma, U, L, 0) {
		result := ""
		for i := 0; i < 2; i++ {
			for j := 0; j < n; j++ {
				result += string(48 + ma[i][j])
			}
			result += ","
		}

		fmt.Println(result)
	}

	fmt.Println("IMPOSSIBLE")
}
