# Minitalk

## Description
Minitalk is a project that involves creating a client-server application using UNIX signals for inter-process communication. The client sends text messages to the server, which displays them upon reception. This project aims to teach how to handle UNIX signals and build basic client-server communication using them.

## Files

- **makefile**: Makefile for compiling the Minitalk project.
- **minitalk.h**: Header file containing function prototypes and constants.
- **src/**: Directory containing source code files.
- **obj/**: Directory for object files generated during compilation.
- **bin/**: Directory for executable binaries generated after compilation.

## Compilation

To compile the Minitalk project, navigate to the root directory and run:
```sh
make
```
## Usage
## Starting the Server
Navigate to the directory where the server executable is located:

```sh
cd bin
```
Start the server:

```sh
./server
```

The server will display its PID (Process ID) upon starting.

## Sending Messages from the Client
1. Navigate to the directory where the client executable is located:
```sh
cd bin
```

2. Send a message to the server:
```sh
./client SERVER_PID "Your message here"
```
Replace SERVER_PID with the PID of the server displayed when it started, and "Your message here" with the message you want to send.

## Example
## Compilation and Execution Example
```sh
make
cd bin
./server
```
In another terminal:

```sh
cd bin
./client SERVER_PID "Hello, Minitalk!"
```
## Contributors
