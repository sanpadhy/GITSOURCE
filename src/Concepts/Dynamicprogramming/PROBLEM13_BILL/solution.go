package main

import (
	"fmt"
)

func getCurrencyOnBill


func main() {
	currency_map := map[int]int {
		500: 2,
		200: 1,
		100: 4,
		50: 6,
		20: 7,
		10: 5,
		5: 10,
		2: 3,
		1: 5,
	}

	type result map[int]int
	resultmap := make(result)

	for key, value := range currency_map {

		fmt.Println("%d: %d", key, value)
	}

}
