/*
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated 

successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of 
alphabetic characters. You can assume the string to be decoded is valid.

*/

package main

import (
	"fmt"
	"strconv"
	"unicode"
	)

func runLengthEncoding(s string) []string {
	i := 0
	count := 1
	var result []string

	firstChar := s[0]

	for i = 1; i < len(s); i++ {
		for s[i] == firstChar {
			count++
		}

		fmt.Println(count)

		countStr := strconv.Itoa(count)
		countStr = countStr + firstChar
		result = append(result, countStr)
		firstChar = s[i]
		count = 1
	}

	if(count > 0) {
		countStr := strconv.Itoa(count)
		countStr = countStr + firstChar
		result = append(result, countStr)
	}

	return result
}

func runLengthdecoding(s string) string {

	return result
}

func main() {
	str := "AAABBCCCCCC"
	var result string
	if !unicode.IsLetter(str[0]) {
		result = runLengthEncoding(str)
	} else {
		result = runLengthDecoding(str)
	}

	fmt.Println(result)

}
