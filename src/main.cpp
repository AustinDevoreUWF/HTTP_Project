#include <iostream>
#include <sys/socket.h>

int main(){
    int s{};

//hardcoded parameters for now
    //returns file descriptor for the socket    
    s = socket(AF_INET,SOCK_STREAM,0);

    connect(s,);
    return 0;
}