// Given an array A of size N, print the reverse of it.
#include <stdio.h>
/*
Given an array A of size N, print the reverse of it.
    Input:
    1
    4
    1 2 3 4
    Output:
    4 3 2 1
*/
int main(){
	
    int cases = 0;
	int len = 0;

    scanf("%d", &cases);

    while (cases > 0){
        scanf("%d",&len);
        int a[len]; 
        for(int i=0; i<len; i++){   scanf("%d", &a[i]);}
        for(int i=len-1; i>-1; i--){    printf("%d ",a[i]);}
        cases--;
        printf("\n");
    }
	return 0;
}