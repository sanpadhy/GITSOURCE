package main

import (
	"fmt"
	"encoding/json"
	"io/ioutil"
	"os"
)

type quiz struct {
	quizSport sport `json:"sport"`
	quizMath maths `json:"maths"`
}

type sport struct {
	question1 q1 `json:"q1"`
}

type maths struct {
	question1 q1 `json:"q1"`
	question2 q2 `json:"q2"`
}

type q1 struct {
	question string `json: "question"`
	options []string `json: "options"`
	answer string `json: "answer"`
}

type q2 struct {
	question string `json: "question"`
	options []string `json: "options"`
	answer string `json: "answer"`
}

func main() {
	jsonfile, err := os.Open("example_2.json")
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Successfully open the example_2.json file.")

	defer jsonfile.Close()

	var result map[string]interface{}

	byteValue, _ := ioutil.ReadAll(jsonfile)
	json.Unmarshal([]byte(byteValue), &result)

	// check how to get the the values in maths and sport. 
	mathResult := result["quiz"].(maths)

	fmt.Println(mathResult)
}
