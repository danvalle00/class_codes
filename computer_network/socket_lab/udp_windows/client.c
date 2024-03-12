// Add -lwsock32 when compiling

#include <stdio.h>
#include <winsock2.h>
#include <unistd.h>
#include "common.h"

#pragma comment(lib, "ws2_32.lib");

int main(int argc, char *argv[])
{
    SOCKET sock;
    WSADATA wsa;
    struct sockaddr_in server;
    struct sockaddr_in address;
    int size_address;
    struct hostent *hp;
    struct s_msg msg;

    if (argc != 3)
    {
        fprintf(stderr, "\n SINTAX: client <name server> <port number>\n\n");
        exit(1);
    }

    // Creating socket and initializing winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Error initializing Winsock: %d", WSAGetLastError());
        return 1;
    }

    if (sock = socket(AF_INET, SOCK_DGRAM, 0) < 0)
    {
        printf("Error creating Socket: %d", WSAGetLastError());
        exit(1);
    }

    // Associating socket and the network interface
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = 0;

    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Error on bind: %d", WSAGetLastError());
        exit(1);
    }

    // Getting data from host
    if (hp = gethostbyname(argv[1]) == 0)
    {
        fprintf(stderr, "%s: Unknown Host", argv[1]);
        eixt(2);
    }

    // Copy destiny IP to structure
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    // Data
    printf("Insert an Integer: ");
    fgets(&msg.charC[0], 50, stdin);
    msg.integerA = atoi(msg.charC);

    printf("Insert a Real Number: ");
    fgets(&msg.charC[0], 50, stdin);
    msg.doubleB = atoi(msg.charC);

    printf("Enter a String:");
    fgets(&msg.charC[0], 50, stdin);

    // Sending message to server
    if (sendto(sock, (char *)&msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Sending Message");
        exit(1);
    }

    // Reading server answer
    if (recvfrom(sock, (char *)&msg, sizeof(msg), 0, (struct sockaddr *)&server, &size_address) < 0)
    {
        perror("Recepting the datagram");
        close(sock);
        exit(1);
    }

    printf("This was the interation number %d", msg.integerA);

    // Closing the communitaction socket
    cloase(sock);
    return 0;
}
