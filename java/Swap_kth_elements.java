#include <stdio.h>
/*
Given an array of size N, swap the kth element from beginning with kth element from end.
    Input
    1
    8 3
    1 2 3 4 5 6 7 8
    Output
    1 2 6 4 5 3 7 8
*/
// Execution Time:0.01
int main() {
    int cases   = 0;
	int len     = 0;
    int kElement   = 0;

    scanf("%d", &cases);

    while ( cases > 0 ){
        scanf("%d %d", &len, &kElement);

        int a[len]; 
        for( int i=0; i<len; i++ ){ 
            scanf("%d", &a[i]);
        }
        
        int aux = a[kElement-1];
        a[kElement-1] = a[len-kElement];
        a[len-kElement] = aux;
        
        cases--;
        for( int i=0; i<len; i++ ){ 
            printf("%d ", a[i]);
        }
        printf("\n");
    }
	return 0;
}