#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define total 10
#define win 4
#define acksuccess (rand()%100 <70)

int main(){
	int base=0;
	int ack[total]={0};
	int sent[total]={0};
	srand(time(0));
	
	while(base<total){
		printf("Sender Window :%d to %d\n",base,(base+win<total)? base+win : total);
		for(int i=0;i<win && i+base<total ;i++){
			int pkt=base+i;
			if(!ack[pkt]){
				printf("Sender : Send Package %d\n",pkt);
				sleep(1);
				if(acksuccess){
					printf("Receiver : Acknowledgment for packet %d received\n",pkt);
					ack[pkt]=1;
					}
				else{
					printf("Receiver : Acknowledgment for packet %d not received\n",pkt);
					}
				}
			}
		while(ack[base] && base<total){
			base++;
			}
		sleep(1);
		printf("\n");
		}
	printf("ALL PACKETS RECEIVED\n");
	return 0;
	}
		
