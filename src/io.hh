#pragma once
#include "buffer.hh"
#include <netinet/in.h>
template <typename T>
class Context {
    private:
        int epoll_fd;
        std::vector<Client> clients;
        int closed, running;
        uint64_t client_num;
        std::vector<Task> tasks;
        std::vector<T> data;

    public:
        explicit Context(int epoll_fd, std::vector<T>& data, uint8_t closed = 1, uint8_t running = 1) : epoll_fd(epoll_fd), 
        data(data)
        {

        }

        void add_client(const Client& client) {
            clients.push_back(client);
        }

        void add_task(const Task& task) {
            tasks.push_back(task);
        }

        

};

class Task {

};

class RunnableTask {

}

class Client {
    private:
        int fd;
        void* data;
        void* next;
        void* on_close;
        Buffer buffer;
        Context* context;
        struct sockaddr_in addr;
    public:
        explicit Client();
        
    
};