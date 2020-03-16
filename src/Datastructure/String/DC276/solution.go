
/* 
    Implement an efficient string matching algorithm.

    That is, given a string of length N and a pattern of length k, write a program that searches for the pattern in the    
    string with less than O(N * k) worst-case time complexity.

    If the pattern is found, return the start index of its location. If not, return False.

*/

package main

import (
    "fmt"
)

func findPatternInString(str string, pattern string) bool {
		if len(str) == 0 || len(pattern) == 0 {
			return false
		}

		slen := len(str)
		plen := len(pattern)
		if plen > slen {
			return false
		}

		var list_string []string

		for k := 0; k < slen-plen+1; k++ {
			list_string = append(list_string, str[k:k+plen])
		}

		fmt.Println(list_string)

		for i := 0; i < len(list_string); i++ {
			if list_string[i] == pattern {
				return true
			}
		}

		return false
}


func main() {
	var str = "abcabcabcd"
	var pattern = "abcd"

	result := findPatternInString(str, pattern)

	fmt.Println(result)
}
