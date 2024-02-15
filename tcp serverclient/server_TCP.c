#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct sockaddr_in server;
    char *message = "GET / HTTP/1.1\r\n\r\n";
    char server_reply[2000];
    int recv_size;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    if ((ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
        std::cout << "Could not create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("192.168.1.1"); // Example IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(ConnectSocket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        std::cout << "Connection failed." << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    if (send(ConnectSocket, message, strlen(message), 0) < 0) {
        std::cout << "Send failed." << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    recv_size = recv(ConnectSocket, server_reply, 2000, 0);
    if (recv_size < 0) {
        std::cout << "Receive failed." << std::endl;
    } else {
        server_reply[recv_size] = '\0'; // Null-terminate the string
        std::cout << "Server reply:\n" << server_reply << std::endl;
    }

    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
