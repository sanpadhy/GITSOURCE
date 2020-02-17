// Between the number from the range of 6 to 20,
// there are three instances where the X * (X+1) exists in that given range.

// 3 * 2 --> 6
// 4 * 3 --> 12
// 5 * 4 --> 20

// Return count, i.e. 3.

package main

import (
	"fmt"
)

func solution(A int, B int) int {

	count := 0

	for i := A; i <= B; i++ {

		if i%2 != 0 {
			continue
		}

		mid := i / 2

		for mid > 0 {
			mult := mid * (mid - 1)

			if mult == i {
				count++
				break
			} else if mult > i {
				mid -= 1
			} else {
				break
			}
		}
	}

	return count
}

func main() {
	cnt := 0

	cnt = solution(6, 20)

	fmt.Println("cnt: %d\n", cnt)
}
