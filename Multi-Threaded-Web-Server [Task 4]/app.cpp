#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <sstream>
#include <dirent.h>

const int PORT = 8080;
const std::string ROOT_DIR = "./www";

void handle_client(int client_socket)
{
    char buffer[1024];
    read(client_socket, buffer, 1024);

    std::istringstream request(buffer);
    std::string method, path, version;
    request >> method >> path >> version;

    if (method == "GET")
    {
        if (path == "/")
        {
            path = "/index.html";
        }

        std::string full_path = ROOT_DIR + path;
        std::ifstream file(full_path);

        if (file.is_open())
        {
            std::stringstream file_content;
            file_content << file.rdbuf();
            std::string content = file_content.str();

            std::string response = "HTTP/1.1 200 OK\r\n";
            response += "Content-Length: " + std::to_string(content.size()) + "\r\n";
            response += "Content-Type: text/html\r\n";
            response += "Connection: close\r\n\r\n";
            response += content;

            write(client_socket, response.c_str(), response.size());
        }
        else
        {
            std::string response = "HTTP/1.1 404 Not Found\r\n";
            response += "Content-Length: 13\r\n";
            response += "Content-Type: text/html\r\n";
            response += "Connection: close\r\n\r\n";
            response += "404 Not Found";

            write(client_socket, response.c_str(), response.size());
        }
    }

    close(client_socket);
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    std::vector<std::thread> threads;

    while (true)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        threads.emplace_back(std::thread(handle_client, new_socket));
    }

    for (auto &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }

    close(server_fd);
    return 0;
}
