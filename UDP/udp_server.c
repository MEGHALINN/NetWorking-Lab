#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){
	int server;
	struct sockaddr_in servaddr,cltaddr;
	char buffer[1024];
	socklen_t addr;
	time_t current_time;
	
	server=socket(AF_INET,SOCK_DGRAM,0);
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port=htons(PORT);
	
	bind(server,(struct sockaddr*)&servaddr , sizeof(servaddr));
	addr=sizeof(cltaddr);
	recvfrom(server,buffer,sizeof(buffer),0,(struct sockaddr*)&cltaddr,&addr);
	printf("Client : %s",buffer);
	
	current_time=time(NULL);
	snprintf(buffer,sizeof(buffer),"%s",ctime(&current_time));
	sendto(server,buffer,sizeof(buffer),0,(struct sockaddr*)&cltaddr,sizeof(cltaddr));
	
	close(server);
	return 0;
	}

