

package main

import (
	"fmt"
	"strings"
)

func findDistanceinWords(text string, s1 string, s2 string) int {

	var lst_str string 
	var last_idx int
	var distance int
	if len(text) == 0 {
		return 0
	}

	for i := 0; str := strings.Split(text, " "); i++ {
		if str == s1 || str == s2 {
			if (str == s1 && lst_str == s2) || (str == s2 && lst_str == s1) {
				distance = i - last_idx + 1
			}
			lst_str = str
			lst_idx = i
		}
	}

	return distance
}

func main()
{
	fmt.Println(findDistanceinWords("dog cat hello cat dog dog hello cat world", "hello", "world"))
}


