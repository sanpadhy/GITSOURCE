//    Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

//    For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

package main

import (
	"fmt"
	"reflect"
)

func itemExists(slice interface{}, item interface{}) bool {
	s := reflect.ValueOf(slice)

	if s.Kind() != reflect.Slice {
		panic("Invalid data-type")
	}

	for i := 0; i < s.Len(); i++ {
		if s.Index(i).Interface() == item {
			return true
		}
	}

	return false
}

func getLongestSubstring(s string, k int) (string, int) {
	if len(s) == 0 {
		return "", 0
	}

	if k == 1 {
		return s[:1], 1
	}

	firstchar := s[0]
	var secondidx int

	for s[secondidx] == firstchar {
		secondidx++
	}

	var seenChar []string
	var count int
	var resultStr string
	var longestStr string

	for i, c := range(s) {
		if itemExists(seenChar, c) {
			seenChar = append(seenChar, string(c))
			count++
		}

		if count > k {
			resultStr = s[:i-1]
		}

			remainStr, longest := getLongestSubstring(s[secondidx:], k)

		if len(resultStr) > longest {
			longestStr = resultStr
		} else {
			longestStr = remainStr
		}
	}

	return longestStr, len(longestStr)
}

func main() {
	fmt.Println(getLongestSubstring("abcba", 2))
}
