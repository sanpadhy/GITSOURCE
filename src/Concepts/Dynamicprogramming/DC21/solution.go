/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

package main

import (
	"fmt"
	)

type classTimes struct {
	start int
	end int
}

func getNoOfClasses(xf []classTimes) int {
	var i int
	totalClasses := len(xf)
	var classRooms []int

	for i = 0; i < totalClasses; i++ {
			classRooms = append(classRooms, 1)
	}

	for i = 1; i < totalClasses; i++ {
		for j := 0; j < i; j++ {
			if xf[i].start < xf[j].start {
				if xf[i].end < xf[j].start {
					if classRooms[i] < classRooms[j] {
						classRooms[i] = classRooms[j]
					}
				} else {
					if classRooms[i] < classRooms[j]+1 {
						classRooms[i] = classRooms[j]+1
					}
				}
			} else {
				if xf[i].start < xf[j].end {
					if classRooms[i] < classRooms[j]+1 {
						classRooms[i] = classRooms[j]+1
					}
				} else {
					if classRooms[i] < classRooms[j] {
						classRooms[i] = classRooms[j]
					}
				}
			}
		}
	}

	return classRooms[i-1]
}

func main() {
	var classes = []classTimes {
		{
			start: 30,
			end: 75,
		},
		{
			start: 0,
			end: 50,
		},
		{
			start: 60,
			end: 150,
		},
		{
			start: 80,
			end: 160,
		},
	}

	noOfClasses := getNoOfClasses(classes)

	fmt.Println(noOfClasses)

}
