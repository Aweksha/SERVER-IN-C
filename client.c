#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to establish connection to the server
int connectToServer(const char *ipAddress, int portNumber) {
    int sd;
    struct sockaddr_in serverAddr;

    // Create a socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0)
        error("ERROR opening socket");

    // Clear serverAddr structure
    bzero((char *)&serverAddr, sizeof(serverAddr));

    // Fill in server address info
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNumber);
    inet_pton(AF_INET, ipAddress, &serverAddr.sin_addr);

    // Connect to the server
    if (connect(sd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        error("ERROR connecting");

    return sd;
}

// Function to send data to the server
void sendData(int sd, const char *data, int dataSize) {
    int n;

    // Convert dataSize to network byte order
    int convertedSize = htonl(dataSize);

    // Send dataSize to the server
    n = write(sd, &convertedSize, sizeof(convertedSize));
    if (n < 0)
        error("ERROR writing to socket");

    // Send data to the server
    n = write(sd, data, dataSize);
    if (n < 0)
        error("ERROR writing to socket");
}

// Function to receive data from the server
void receiveData(int sd) {
    int n, dataSize;
    char buffer[MAX_BUFFER_SIZE];

    // Receive dataSize from the server
    n = read(sd, &dataSize, sizeof(dataSize));
    if (n < 0)
        error("ERROR reading from socket");

    // Convert dataSize to host byte order
    dataSize = ntohl(dataSize);

    // Receive data from the server
    n = read(sd, buffer, dataSize);
    if (n < 0)
        error("ERROR reading from socket");

    // Null-terminate the received data
    buffer[n] = '\0';

    printf("I'm expecting you to send %d bytes\n", dataSize);

    // Print the received data
    printf("Server Response: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    int sd, portNumber;
    char ipAddress[INET_ADDRSTRLEN];
    char input[MAX_BUFFER_SIZE];

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    // Extract IP address and port number from command line arguments
    strcpy(ipAddress, argv[1]);
    portNumber = atoi(argv[2]);

    // Establish connection to the server
    sd = connectToServer(ipAddress, portNumber);

    // Ask user for input string
    printf("Enter a string (max 255 characters): ");
    fgets(input, MAX_BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

    // Send data to the server
    sendData(sd, input, strlen(input));

    // Receive data from the server
    receiveData(sd);

    // Close the socket
    close(sd);

    return 0;
}
