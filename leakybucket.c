#include <stdio.h>

void main(){
    int size, n, input, output, curr;

    printf("\nEnter Bucket Size: ");
    scanf("%d", &size);

    printf("\nEnter Flow Rate: ");
    scanf("%d", &output);

    printf("\nEnter Number of Inputs: ");
    scanf("%d", &n);

    curr = 0;
    for(int i=0; i<n; i++){
        printf("\nEnter Incoming packet sizes: ");
        scanf("%d", &input);

        if(input <= (size - curr)){
            curr += input;
            printf("\nBucket Size is %d / %d\n", curr, size);
        }
        else {
            printf("\ndropped %d packets: ", input - (size - curr)); 
            curr = size; // Ensure bucket is correctly updated
            printf("\nBucket Size is %d / %d\n", curr, size);
        }

        // Prevent curr from going negative
        curr = (curr - output >= 0) ? curr - output : 0;
        printf("\n%d packets remaining", curr);
    }
}

