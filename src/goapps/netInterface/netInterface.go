// netInterface
package main

import (
	"fmt"
	"net"
)

/*
type Interface struct {
	Index int
	MTU   int
	Name  string
	//	hardwareaddr Ha
	//	HardwareAddr HardwareAddr
	//	Flags        Flags
}
*/

func main() {
	interfaces, err := net.Interfaces()
	if err != nil {
		fmt.Print(err)
		return
	}

	for _, i := range interfaces {
		fmt.Printf("Interface: %v\n", i.Name)
		byName, err := net.InterfaceByName(i.Name)
		if err != nil {
			fmt.Println(err)
		}
		addresses, err := byName.Addrs()
		for k, v := range addresses {
			fmt.Printf("Interface Address #%v: %v\n", k, v.String())
		}
		fmt.Println("Interface Flags:", i.Flags.String())
		fmt.Println("Interface MTU:", i.MTU)
		fmt.Println("Interface Hardware Address:", i.HardwareAddr)
		fmt.Println()
	}
}
