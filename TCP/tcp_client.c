#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 8080

int main(){
	int client;
	struct sockaddr_in servaddr;
	char buffer[1024]={0};
	
	client=socket(AF_INET,SOCK_STREAM,0);
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(8080);
	
	connect(client,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
	send(client,"Hello from client",17,0);
	read(client,buffer,1024);
	printf("Client says: %s",buffer);
	
	close(client);
	return 0;
	}
