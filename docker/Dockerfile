FROM golang:latest
MAINTAINER santosh.padhy@gmail.com
RUN mkdir /DNS
ADD DNS /DNS
WORKDIR /DNS
RUN go get github.com/gorilla/mux
RUN go build dns.go   
EXPOSE 3000
CMD ["/DNS/dns"]
