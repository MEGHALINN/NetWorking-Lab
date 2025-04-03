#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){
	int server,client;
	struct sockaddr_in  servaddr;
	socklen_t slen=sizeof(servaddr);
	char buffer[1024]={0};
	
	server=socket(AF_INET,SOCK_STREAM,0);
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port=htons(PORT);
	
	bind(server,(struct sockaddr*)&servaddr ,slen);
	listen(server,3);
	
	client=accept(server,(struct sockaddr*)&servaddr ,&slen);
	
	while(1){
		memset(buffer,0,sizeof(buffer));
		read(client,buffer,sizeof(buffer));
		printf("Client : %s",buffer);
		if(strcmp(buffer,"exit")==0) 
			break;
		
		printf("Server :");
		fgets(buffer,sizeof(buffer),stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		send(client,buffer,sizeof(buffer),0);
		
		}
	
	close(client);
	close(server);
	return 0;
	}
		
		
		
	
	
