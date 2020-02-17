// main.go
package main

import (
    "fmt"
    "log"
    "net/http"
    "time"
)
func handler(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "Hello World!\n")
}

func main() {
    srv := http.Server{
        Addr:         ":8080",
        ReadTimeout:  time.Minute,
        WriteTimeout: time.Minute,
    }
    http.HandleFunc("/", handler)
    done := make(chan os.Signal, 1)
    signal.Notify(done, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)

    go func() {
        srv.ListenAndServe()
    }()
    <-done
    err := srv.Shutdown(context.Background())
    if err != nil {
        log.Fatal(err)
    }
}
