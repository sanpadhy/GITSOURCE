package main

import (
    "fmt"
    "log"
    "net/http"

    jwt "github.com/dgrijalva/jwt-go"
)

var mySigningKey = []byte("captainjacksparrowsayshi")

// If the JWT is valid, it will then return the highly confidential hello world message back to the client, otherwise it’ll return not authorized.

func homePage(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "Hello World")
    fmt.Println("Endpoint Hit: homePage")

}

func isAuthorized(endpoint func(http.ResponseWriter, *http.Request)) http.Handler {
    return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {

        if r.Header["Token"] != nil {
			// When our client goes to hit our server API, it will include this JWT as part of the request.
            token, err := jwt.Parse(r.Header["Token"][0], func(token *jwt.Token) (interface{}, error) {
                if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
                    return nil, fmt.Errorf("There was an error")
                }
                return mySigningKey, nil
            })

            if err != nil {
                fmt.Fprintf(w, err.Error())
            }

			// Our server will be able to read this JWT and validate the token using the same passphrase.
            if token.Valid {
                endpoint(w, r)
            }
        } else {

            fmt.Fprintf(w, "Not Authorized")
        }
    })
}

func handleRequests() {
    http.Handle("/", isAuthorized(homePage))
    log.Fatal(http.ListenAndServe(":9000", nil))
}

func main() {
    handleRequests()
}
