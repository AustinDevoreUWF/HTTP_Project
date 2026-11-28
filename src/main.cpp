#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

#define BACKLOG 10

int main(){
    int s_fd {}, client_fd {};//file descriptors;
    int status{};
    struct addrinfo hints{};
    struct addrinfo *server_inf = nullptr;
    struct sockaddr_storage incoming_sockaddr; 

    //start off with emptying the hints struct
    std::memset(&hints,0,sizeof(hints));
    //now we want to say: we dont care, IPv4 || IPv6
    hints.ai_family = AF_UNSPEC;
    //we are using TCP
    hints.ai_socktype = SOCK_STREAM;
    //we want to direct to any local IP for whatever reason
    hints.ai_flags = AI_PASSIVE;

    if((status = getaddrinfo(nullptr,"8080",&hints,&server_inf)) !=0){
        std::cerr << gai_strerror(status);//prints an output that is human readable
        exit(1);
    }

    //hardcoded parameters for now
        //returns file descriptor for the socket    
    s_fd = socket(server_inf->ai_family,server_inf->ai_socktype,server_inf->ai_protocol);

    //fill in the socketStruct that holds info
    bind(s_fd,server_inf->ai_addr,server_inf->ai_addrlen);
    //takes in incoming request and puts them in a queue to be taken off by accept() call.
    //(socket_fd,num of request allowed in queue) 
    if(listen(s_fd, BACKLOG) != -1){
        std::cerr <<'('<<errno<<"): "<<strerror(errno)<<'\n';
    };


    // accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    socklen_t incoming_sock_size = sizeof(incoming_sockaddr);
    //accept fills in the clients socketInfo, give you the 
    client_fd = accept(s_fd,(sockaddr*)&incoming_sockaddr, &incoming_sock_size);
    freeaddrinfo(server_inf,);
    return 0;
}
