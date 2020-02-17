package main

import "testing"

// Testing package will do two things. Failing shoftly or failing very hardly.
func TestSum(t *testing.T) {

	tt := []struct {
		name    string
		numbers []int
		sum     int
	}{
		{"One to five", []int{1, 2, 3, 4, 5}, 15},
		{"zero", nil, 0},
		{"one negative one", []int{1, -1}, 1},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			s := Sum(tc.numbers...)
			if s != tc.sum {
				t.Errorf("%s Expected sum %v, but got %v", tc.name, tc.sum, s)
			}
		})
	}
}

func TestsumOfNumbers(t *testing.T) {
	t.Errorf("This test failed because I said so. ")
	//	t.Fatalf("This test failed and stoped running. ")
}
