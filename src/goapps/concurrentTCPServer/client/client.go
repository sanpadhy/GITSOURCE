// wsClient
package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
)

// go run TCPclient.go localhost:8001

// If the second parameter does not
// contain an IP address, but only a port number, net.Listen() will listen on all available IP
// addresses of the local system.

func main() {
	arguments := os.Args
	if len(arguments) == 1 {
			fmt.Println("Please provide the command file: ")
		return
	}

	CONNECT := arguments[1]

	// net.ResolveTCPAddr() function returns the address of a TCP end point ( type
	// TCPAddr ) and can only be used for TCP networks.

	tcpAddr, err := net.ResolveTCPAddr("tcp4", CONNECT)

	if err != nil {
		fmt.Println("ResolveTCPAddr:", err.Error())
		return
	}

	//net.Dial() function is used for connecting to the remote server.
	// c, err := net.Dial("tcp", CONNECT)

	c, err := net.DialTCP("tcp4", nil, tcpAddr)
	if err != nil {
		fmt.Println("DialTCP:", err.Error())
		return
	}

	for {
		reader := bufio.NewReader(os.Stdin)
		fmt.Print(">> ")

		//Ignoring the error value returned by reader.ReadString() is not
		// a good practice.
		text, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Fprintf(c, text+"\n")

		message, _ := bufio.NewReader(c).ReadString('\n')
		fmt.Print("->: " + message)
		if strings.TrimSpace(string(text)) == "STOP" {
			fmt.Println("TCP client exiting...")
			return
		}
	}
}
