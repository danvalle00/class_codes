// Add -lwsock32 when compiling

#include <stdio.h>
#include <winsock.h>
#include <unistd.h>
#include "common.h"

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    SOCKET sock;
    WSADATA wsa;
    struct sockaddr_in server;
    struct hostent *hp;
    struct s_msg msg;

    if (argc != 2)
    {
        fprintf(stderr, "\n SINTAX: client <name server>\n\n");
        exit(1);
    }

    // Initialize Winsock and create socket
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Error initializing Winsock: %d", WSAGetLastError());
        return 1;
    }

    if (sock = socket(AF_INET, SOCK_STREAM, 0) < 0)
    {
        printf("Error creating socket: %d", WSAGetLastError());
        exit(1);
    }

    if (hp = gethostbyname(argv[1]) == 0)
    {
        fprintf(stderr, "%s, Host Unknown");
        exit(2);
    }

    memcpy(&server.sin_addr, hp->h_addr, hp->h_length); // Copy the server IP address to connection struture
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_DOOR); // Configure the server port for the connection

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) // Connect with server
    {
        perror("Connection: ");
        exit(1);
    }

    // Data to send
    printf("Enter an Integer: ");
    fgets(&msg.charC[0], 50, stdin);
    msg.integerA = atoi(msg.charC);

    printf("Enter a Real Number: ");
    fgets(&msg.charC[0], 50, stdin);
    msg.doubleB = atof(msg.charC);

    printf("Enter a String: ");
    fgets(&msg.charC[0], 50, stdin);

    // Send the data to server
    if (send(sock, (char *)&msg, sizeof(msg), 0) < 0)
    {
        perror("Message Sending");
        close(sock);
        exit(1);
    }

    // Read the server answer
    if (recv(sock, (char *)&msg, sizeof(msg), 0) < 0)
    {
        perror("Receiving the Response");
        close(sock);
        exit(1);
    }

    printf("This was the interation number: %d", msg.integerA);

    close(sock); // close the communication socket
    return 0;
}
