#include <stdio.h>
/*
Given an array arr[] of positive integers of size N. 
Print the reverse of every sub-array of K group elements.
    Input
    2
    5 3
    1 2 3 4 5
    6 2
    10 20 30 40 50 60
    
    Output
    3 2 1 5 4
    20 10 40 30 60 50

*/
// if the last group is not complete then it does not reverse them only prints them
void solution1(){
    int cases = 0;
	int len = 0;
    int steps = 0;

    scanf("%d", &cases);

    while ( cases > 0 ){
        scanf("%d %d",&len, &steps);

        int a[len]; 
        for( int i=0; i<len; i++ ){   scanf("%d", &a[i]);}
        
        for( int j=0; j < len; j += steps ){
            int i = j + steps - 1;
            if( i < len){ 
                for( ; i >= j; i-- ){ printf("%d ", a[i]); }
            }else{
                for( i=j; i < len; i++){ printf("%d ", a[i]); }
                j = len;
            }
        }
        cases--;
        printf("\n");
    }
}

// Execution Time:0.38
// Everything is reversed even if the group is not complete
void solution2(){
    int cases = 0;
	int len = 0;
    int steps = 0;

    scanf("%d", &cases);

    while ( cases > 0 ){
        scanf("%d %d",&len, &steps);

        int a[len]; 
        for( int i=0; i<len; i++ ){   scanf("%d", &a[i]);}
        
        for( int j=0; j < len; j += steps ){
            int i = j + steps - 1;
            if( i >= len){ i = len-1; }
            for( ; i >= j; i-- ){ printf("%d ", a[i]); }
        }
        cases--;
        printf("\n");
    }
}

int main(){
    // solution1();
    solution2();
	return 0;
}