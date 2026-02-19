// important note , this code is not secure
// it should be used only in educational or testing enviroments
// you are informed now 

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg){
  perror(msg);
}

int serv( char *ip , int port){

  // init the socket descriptor
  int sockfd = socket( AF_INET , SOCK_STREAM , 0); // AF_INET is the TCP Flag 

  if ( sockfd == -1){
    error("failed to init the socket descriptor");
  }

  // init the the socket struct ( contains , ip , port , and type/family )
  memset(&server , sizeof(server)); // this clears the struct
  struct sockaddr_in server;

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(ip);
  server.sin_port = htons(port)




}

int main(){
  printf("hello world\n");

}
