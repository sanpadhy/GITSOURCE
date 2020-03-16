// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
// For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
// You can assume that the messages are decodable. For example, '001' is not allowed.

package main

import (
	"fmt"
	"strconv"
	)


func isValidCode(num int) int {
	return func() int {
		if num < 1 || num > 26 {
			return 0
		} else {
			return 1
		}
	}()
}

func getNumOfEncode(num int) int {

	if num == 0 {
		return 0
	}

	var count int
	numstr := strconv.Itoa(num)

	if len(numstr) == 1 {
		return 1
	} else if len(numstr) == 2 {
		return 1 + isValidCode(num)
	} else {
		tstr, _ := strconv.Atoi(numstr[1:])
		count = getNumOfEncode(tstr)

		tstr, _ = strconv.Atoi(numstr[:2])
		if isValidCode(tstr) != 0 {
			tstr, _ = strconv.Atoi(numstr[2:])
			count += getNumOfEncode(tstr)
		}
	}

	return count
}

func main() {
	fmt.Println(getNumOfEncode(0))
}
