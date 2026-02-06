#include <stdio.h>
/*
Given an integer array A of size N, find sum of elements in it.
    Input:
    2
    3
    3 2 1
    4
    1 2 3 4
    Output:
    6
    10
*/
int main(){
	
    int cases = 0;
	int len = 0;

    printf("\nHow many test would you like to do? "); scanf("%d", &cases);

    while (cases > 0){
        int sum = 0;
        printf("\n\tCase: %d",cases);
        printf("\nEnter the length of the array: "); scanf("%d",&len);
        int a[len]; 
        printf("\nEnter the number followed by enter\n");
        for(int i=0; i<len; i++){   
            printf("a[%d]: ",i);
            scanf("%d",&a[i]);
            sum +=a[i];
        }
        printf("\n\tThe sum of all the numbers entered is: %d\n",sum);
        cases--;
    }

    printf("\nThanks for using the program!");
	return 0;
}