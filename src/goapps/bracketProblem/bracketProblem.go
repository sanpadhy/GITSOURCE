// bracketProblem
package main

import (
	"fmt"
)

type stack struct {
	br  []string
	top int
}

var stk stack

func stackEmpty() bool {
	if stk.top == 0 {
		return true
	}

	return false
}

func pushStack(s string) {
	stk.br = append(stk.br, s)
	stk.top++
}

func popStack() {
	// Truncate the slice to remove the element
	stk.br = stk.br[:stk.top-1]
	stk.top--
}

func BalancedStringLaterals(s string, br map[string]string) bool {
	for i, _ := range(s) {
		st := br[string(s[i])]
		if stackEmpty() == false && st == stk.br[stk.top-1] {
			popStack()
		} else {
			pushStack(string(rune(s[i])))
		}
	}

	if status := stackEmpty(); status == true {
		return true
	}

	return false
}

func main() {
	br := map[string]string{
		"}": "{",
		"]": "[",
		")": "(",
	}

	s := "{[{(){}}]}"

	status := BalancedStringLaterals(s, br)

	fmt.Println("Status: %d", status)
}
