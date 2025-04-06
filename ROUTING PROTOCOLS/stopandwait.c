#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define tot_packets 5
#define success 70
#define acksuccess (rand() %100 <success)

int main(){
	srand(time(0));
	int packet=1;
	int ack_received;
	
	while(packet<=tot_packets){
		printf("Sender :Sending Packet %d\n",packet);
		sleep(1);
		
		ack_received=acksuccess;
		
		if(ack_received){
			printf("Receiver:Received acknowlegment for packet %d\n",packet);
			packet++;
			}
		else{
			printf("Receiver : Acknowledgement not received\n");
			sleep(2);
			}
		 }
	printf("All packets send successfully\n");
	return 0;
	}
	