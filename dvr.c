#include <stdio.h>
#define inf 9999
#define max 20

int cost[max][max],table[max][max],nexthop[max][max],n;
void dvr(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			table[i][j]=cost[i][j];
			if(cost[i][j]!=inf && i!=j)
				nexthop[i][j]=j+1;
			else
				nexthop[i][j]=-1;
			}
		}
	int updated;
	do{
		updated=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(table[i][j]>table[i][k]+table[k][j]){
						table[i][j]=table[i][k]+table[k][j];
						nexthop[i][j]=nexthop[i][k];
						updated=1;
						}
					}
				}
			}
		}while(updated);
	}
void printRoutingTables() {
    for (int i = 0; i < n; i++) {
        printf("\nRouter %d's Routing Table:\n", i + 1);
        printf("Destination     Cost    Next Hop\n");
        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("%d              %d       %d\n", j + 1, table[i][j], nexthop[i][j]);
            } else {
                printf("%d              %d       %d\n", j + 1, 0, i + 1);  // Itself
            }
        }
    }
}
	
int main() {
    printf("Enter the number of routers: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (enter %d for no direct link):\n", inf);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    dvr();
    printRoutingTables();

    return 0;
}

