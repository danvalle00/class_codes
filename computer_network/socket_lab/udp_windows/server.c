#include <stdio.h>
#include <unistd.h>
#include <winsock2.h>
#include "common.h"

#pragma comment(lib, "ws2_32.lib");

int main(void)
{
    SOCKET sock;
    WSADATA wsa;
    int cli_len, size;
    struct sockaddr_in address;
    struct sockaddr_in cli_addr;
    struct s_msg msg;
    unsigned char ip[4];
    int interationCounter = 0;

    // Initializing Winsock and creating UDP Socket
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Error initializing Winsock: %d", WSAGetLastError());
        return 1;
    }

    if (sock = socket(AF_INET, SOCK_DGRAM, 0) < 0)
    {
        printf("Error creating socket: %d", WSAGetLastError());
        exit(1);
    }

    // Associating socket with local IP
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = 0;

    // Binding
    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Error Binding: %d", WSAGetLastError());
        exit(1);
    }

    // Getting and showing the socket port value
    size = sizeof(address);
    if (getsockname(sock, (struct sockaddr *)&address, &size) < 0)
    {
        perror("Getting socket address \n");
        exit(1);
    }
    printf("Socket Door: #%d\n", ntohs(address.sin_port));

    // Reading the message
    while (1)
    {
        if (recvfrom(sock, (char *)&msg, sizeof(msg), 0, (struct sockaddr *)&cli_addr, &cli_len) < 0)
        {
            perror("Receiving the data");
            close(sock);
            exit(1);
        }

        memcpy(&ip, &cli_addr, 4); // Splitting in 4 the client IP Address

        printf("Message from: \"%d.%d.%d.%d\": \n ", ip[0], ip[1], ip[2], ip[3]);
        printf("Integer -> %d", msg.integerA);
        printf("Real ----> %f", msg.doubleB);
        printf("String --> %s", msg.charC);

        // Sending the server answer
        msg.integerA = ++interationCounter;
        if (sendto(sock, (char *)&msg, sizeof(msg), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) < 0)
        {
            perror("Sending Message");
            exit(1);
        }
    }

    // Close the communication socket
    close(sock);
    return 0;
}
