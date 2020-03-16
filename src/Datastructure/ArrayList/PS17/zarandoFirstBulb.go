// zarandoFirstBulb
package main

import (
	"fmt"
)

func solution(A []int) int {
	TA := make([]int, len(A)+1)
	shine := 0

	for i := 0; i < len(A); i++ {
		if A[i] == 1 {
			TA[A[i]] = 1
			shine++
		} else {
			TA[A[i]] = 1
			for j := 1; j < A[i]; i++ {
				if TA[j] != 1 {
					goto BREAKME
				}
			}

			shine++

		BREAKME:
		}
	}

	return shine
}

func main() {
	count := 0
	count = solution([]int{1, 3, 4, 2, 5})

	fmt.Println("count: %d", count)
}
