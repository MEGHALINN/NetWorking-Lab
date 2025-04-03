#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

int main(){
	int server,client;
	struct sockaddr_in servaddr;
	int slen=sizeof(servaddr);
	char buffer[1024]={0};
	
	server=socket(AF_INET,SOCK_STREAM,0);
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port=htons(PORT);
	
	bind(server,(struct sockaddr*)&servaddr,slen);
	
	listen(server,3);
	
	client=accept(server,(struct sockaddr*)&servaddr,(socklen_t*)&slen);
	
	read(client,buffer,1024);
	printf("Client send : %s",buffer);
	send(client,"Hello from Server",17,0);
	
	close(server);
	close(client);
	return 0;
	}	
	
