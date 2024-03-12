#include <stdio.h>
#include <winsock2.h>
#include <unistd.h>
#include "common.h"

#pragma comment(lib, "ws2_32.lib")

int main(void)
{
    SOCKET sock;
    SOCKET msgSock;
    WSADATA wsa;
    int cli_len, size;
    struct sockaddr_in server;
    struct sockaddr_in cli_addr;
    struct s_msg msg;
    unsigned char ip[4];
    int interationCounter = 0;

    // Initialize Winsock and Create socket
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Error initializing Winsock: %d", WSAGetLastError());
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0) < 0))
    {
        printf("Error creating socket: %d", WSAGetLastError());
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_DOOR);

    // binds socket and network interface
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        print("Bind Fail: %d", WSAGetLastError());
        exit(1);
    }

    listen(sock, 5);
    while (1)
    {
        cli_len = sizeof(struct sockaddr_in);

        if (msgSock = accept(sock, (struct sockaddr *)&cli_addr, &cli_len) < 0)
        {
            printf("Error accepting: %d", WSAGetLastError());
        }
        else // Established Connection
        {
            if (recv(msgSock, (char *)&msg, sizeof(msg), 0) < 0)
            {
                perror("Error reading message");
            }
            else
            {
                memcpy(&ip, &cli_addr.sin_addr, 4);
                printf("Message from: \"%d.%d.%d.%d\": \n ", ip[0], ip[1], ip[2], ip[3]);
                printf("Integer -> %d\n", msg.integerA);
                printf("Double --> %f\n", msg.doubleB);
                printf("String --> %s\n\n", msg.charC);
            }
        }

        msg.integerA = ++interationCounter;
        if (send(msgSock, (char *)&msg, sizeof(msg), 0) < 0)
        {
            perror("Sending the response: ");
        }
        close(msgSock);
    }
    close(sock);
    return 0;
}
