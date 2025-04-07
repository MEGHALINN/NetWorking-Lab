// server.c
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERV_TCP_PORT 5035  
#define MAX 60             

char buff[4096];  
FILE *f1;

int main()
{
    int sockfd, newsockfd, clength;
    struct sockaddr_in serv_addr, cli_addr;
    char str[MAX], pid_str[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;          
    serv_addr.sin_addr.s_addr = INADDR_ANY;  
    serv_addr.sin_port = htons(SERV_TCP_PORT); 

    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5); 

    clength = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clength);
    close(sockfd); 

    read(newsockfd, str, MAX);
    printf("\nClient message\n File Name : %s\n", str);

    // Send server process ID to client
    sprintf(pid_str, "%d", getpid());
    write(newsockfd, pid_str, MAX);

    f1 = fopen(str, "r");
    if (!f1) {
        perror("File not found");
        return 1;
    }

    while (fgets(buff, 4096, f1) != NULL)
    {
        write(newsockfd, buff, MAX);
    }

    fclose(f1);
    printf("\nFile Transferred\n");

    return 0;
}
