
# To fetch go dependencies from a private repository you need to setup git credentials within the docker image build.
# Used with netrc file. 

# First stage: build the executable.
FROM golang:1.12.5-alpine AS builder


# git is required to fetch go dependencies
RUN apk add --no-cache ca-certificates git

# Create the user and group files that will be used in the running 
# container to run the process as an unprivileged user.
RUN mkdir /user && \
    echo 'nobody:x:65534:65534:nobody:/:' > /user/passwd && \
    echo 'nobody:x:65534:' > /user/group

# Copy the predefined netrc file into the location that git depends on
COPY ./netrc /root/.netrc
RUN chmod 600 /root/.netrc

# Set the working directory outside $GOPATH to enable the support for modules.
WORKDIR /src

# Fetch dependencies first; they are less susceptible to change on every build
# and will therefore be cached for speeding up the next build
COPY ./go.mod ./go.sum ./
RUN go mod download

# Import the code from the context.
COPY . .# Build the executable to `/app`. Mark the build as statically linked.
RUN CGO_ENABLED=0 go build \
    -installsuffix 'static' \
    -o /app .

# Final stage: the running container.
FROM scratch AS final

# Import the user and group files from the first stage.
COPY --from=builder /user/group /user/passwd /etc/

# Import the Certificate-Authority certificates for enabling HTTPS.
COPY --from=builder /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/

# Import the compiled executable from the first stage.
COPY --from=builder /app /app# Perform any further action as an unprivileged user.
USER nobody:nobody

# Run the compiled binary.
ENTRYPOINT ["/app"]
