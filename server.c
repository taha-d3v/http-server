// important note , this code is not secure
// it should be used only in educational or testing enviroments
// you are informed now 

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void error(char *msg){
  perror(msg);
}

void serv( char *ip , int port){

  // init the socket descriptor
  int sockfd = socket( AF_INET , SOCK_STREAM , 0); // AF_INET is the TCP Flag 

  if ( sockfd == -1){
    error("failed to init the socket descriptor");
  }

  // init the the socket struct ( contains , ip , port , and type/family )
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(ip); //  NOTE: update this
  server.sin_port = htons(port);


  if ( bind(sockfd , (struct sockaddr *)&server , sizeof(server)) ){
    error("can't bind ip to socket");
  }

  printf("socket binded with success\n");


  if ( listen(sockfd , 3) < 0 ){
      error("can't init the server to listen");
    }
    
  printf("listening on port %d\n" , port);

  close(sockfd)

  }



int main(){

  char ip[MAX_BUFFER_SIZE];
  int port;
  int ip_len;

  printf("Ip addr : ");
  fgets(ip , sizeof(ip) , stdin);

  ip_len = strlen(ip);
  
  if (ip_len >0 && ip[ip_len - 1] == '\n'){ ip[ip_len - 1] = '\0';}

  printf("port number : "); // NOTE : add port number checker
  scanf("%d" , &port);

  serv(ip , port);
}
