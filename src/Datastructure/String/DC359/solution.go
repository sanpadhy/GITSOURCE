/*
You are given a string formed by concatenating several words corresponding to the integers zero through nine and then anagramming.

For example, the input could be 'niesevehrtfeev', which is an anagram of 'threefiveseven'. Note that there can be multiple instances of each integer.

Given this string, return the original integers in sorted order. In the example above, this would be 357.

*/

package main

import (
	"fmt"
)
/*
var numMap = make(map[string]int) {
	"zero": 0,
	"one": 1,
	"two": 2,
	"three": 3,
	"four": 4,
	"five": 5,
	"six": 6,
	"seven": 7,
	"eight": 8,
	"nine": 9,
}
*/

func findMatchingNumber(s string) int {
	var countTable map[string]int
	for _, c := range s {
		countTable[string(c)]++
	}

	fmt.Println(countTable)
	return 54
}


func main() {
	var s = "niesevehrtfeev"
	fmt.Println(findMatchingNumber(s))
}
