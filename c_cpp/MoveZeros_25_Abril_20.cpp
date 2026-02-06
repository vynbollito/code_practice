#include <stdio.h>

// This auxiliar variable will help us to find the number, different from 0, will be placed
int moveHere = 0;
// Examples
int array[9]          = {1, 0, 0, 0, 3, 8, 9, 0, 12};
// int array[7]       = {0, 0, 3, 0, 5, 7, 9};
// int array[7]       = {1, 2, 3, 0, 4, 5, 6};
// int array[7]       = {0, 0, 0, 0, 0, 0, 9};
// int array[7]       = {1, 3, 5, 0, 7, 0, 9};
// int array[10]      = {1, 0, 0, 1, 0, 0, 2, 0, 4, 0};
// int array[10]      = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void displayArray(){
    for(int i = 0; i < 10; i++){
        printf("%d ",a[i]);
    }
}

void moveZeros(){
    for (int current = 0; current < 9; current++){
        // Find the numbers that are not zeros to be moved to the begining of the array
        if(array[current] != 0){
            array[moveHere++] = array[current];   // switch // and move to next cell
        }
    }
    /* Until this point all the numbers that are not 0 are in place now 'clean'
        not place the zeros at the end of the array
    */
    while (moveHere < 9){
        array[moveHere++] = 0;       // fill the rest of the array with zeros // next position
    }
}

int main()
{
    // 1. Display the initial values of the array
    printf("\n\tOriginal Array\n\t");
    displayArray();
    
    // 2. Move zeros at end
    moveZeros();
    
    // 3. Display the new version of the array
    printf("\n\n\tNew Array\n\t");
    displayArray();

    return 0;
}