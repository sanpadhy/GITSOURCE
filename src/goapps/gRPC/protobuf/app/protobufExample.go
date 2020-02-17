// protobufExample.go
package main

import (
	"fmt"
	"log"

	"github.com/golang/protobuf/proto"
)

func main() {
	fmt.Println("Hello World!")

	santosh := &Person{
		Name: "santosh",
		Age:  24,
	}

	data, err := proto.Marshal(santosh)
	if err != nil {
		log.Println("Marshalling error", err)
	}

	fmt.Println(data)

	newsan := &Person{}

	err = proto.Unmarshal(data, newsan)
	if err != nil {
		log.Println("Unmarshal Failed.", err)
	}

	fmt.Println(newsan.GetAge())
	fmt.Println(newsan.GetName())
}
