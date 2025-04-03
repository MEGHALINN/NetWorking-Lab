#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){
	int client;
	struct sockaddr_in servaddr;
	char buffer[1024]="Time request";
	socklen_t addr;
	
	client=socket(AF_INET,SOCK_DGRAM,0);
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);
	
	sendto(client,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
	addr=sizeof(servaddr);
	recvfrom (client,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,&addr);
	printf("Server : %s",buffer);
	
	close(client);
	return 0;
	}
