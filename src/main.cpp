#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

int main(){
    int s_fd{};
    int status{};
    struct addrinfo hints{};
    struct addrinfo *server_inf;

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
    
    connect(s,);
    freeaddrinfo(server_inf);
    return 0;
}