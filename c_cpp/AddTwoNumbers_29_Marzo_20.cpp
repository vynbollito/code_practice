#include <stdio.h>
#include <stdlib.h>
/*
    You are given two linked-lists representing two non-negative integers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.
    
    Example:
        
    Input:      (9 -> 4 -> 8) 
            +   (1 -> 2 -> 6 -> 5)
                -------------
    Output:      1 -> 1 -> 4 -> 1
    
    Explanation: 849 + 562 = 1411
*/
typedef struct node{
    int value;
    // named like above
    struct node * next;
}node;

void display(node * root){
    node * current = root;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    // free(current);
}

int listLength(node * root){
    node * current = root;
    int count = 0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    // free(current);
    return count;
}

node * createNode(int value){
    node * newNode = (node*)malloc(sizeof(node));
    newNode->value = value; 
    newNode->next = NULL;
    return newNode;
}

// The head will point to the last node added
// This function is used for adding first elements
node * insert(int value, node * root){
    node * newNode = NULL;
    // If there is an existing linked-list just add it else create it
    if(root != NULL){
        newNode = createNode(value);
        newNode->next = root;
        return newNode;
    }else{ 
        return createNode(value);
    }
}

// Add the new node at the end of the linked-list
node * insertReversed(int value, node * root){
    node * newNode = NULL;
    // If there is an existing linked-list just add it else create it
    if(root != NULL){
        newNode = createNode(value);
        // find the last element of the list and add the new node
        node * lastNode = root;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        // free(lastNode);
        return root;
    }else{ 
        return createNode(value);
    }
}

node * reverseList(node * root){
    node * current  = root;
    node * next     = NULL;
    node * prev     = NULL;
    
    while( current != NULL ){
    	next            = current->next;
    	current->next   = prev;
    	prev            = current;
    	current         = next;
    }
    root = prev;
    // free(current);
    // free(next);
    // free(prev);
    return root;
}

node * copyLinkListElements(node * origin, node * destiny){
    while(origin != NULL){
        destiny = insertReversed(origin->value, destiny);
        origin = origin->next;
    }
    return destiny;
}

node * addTwoNumbers(node * origin, node * secondList){
    // Stores the adition of both nodes
    int value = 0;
    // if the result of the last two elements is greater than a single digit
    // we will save it for the next node
    int nextDigit = 0;
    // The head of the list will be not lose even though we get untill the last element
    node * destiny = origin;

    while(secondList != NULL){
        value = destiny->value + secondList->value + nextDigit;
        
        // Valid the sum is a single digit
        if(value > 9){
            // nextDigit has the digit to add in the next sum
            // value contains the remaining digit
            nextDigit       = (value/10)%10;
            value           = value%10;
            destiny->value  = value; 
        }else{
            nextDigit       = 0;
            destiny->value  = value;
        }
        destiny     = destiny->next;
        secondList  = secondList->next;
    }
    if(nextDigit != 0){
        if( listLength(destiny) != listLength(secondList) ){
            destiny->value  = nextDigit;
        }else{
            origin = insertReversed(nextDigit, origin);
        }
    }
    return origin;
}

node * addNumbers(node * d1, node * d2, node * d3){
    node * secondList = NULL;
    // 1. Find the shortest linked-list to fill up the empty spaces
    int len1 = listLength(d1);
    int len2 = listLength(d2);
    
    if( len1 <= len2 ){
        d3 = copyLinkListElements(d2, d3);
        for (int i = len1; i < len2; i++){
            d1 = insert(0, d1);
        }secondList = d1;
    }else if( ( len1 > len2 ) ){
        d3 = copyLinkListElements(d1, d3);
        
        for (int i = len2; i < len1; i++){
            d2 = insert(0, d2);
        }secondList = d2;
    }
    // 3. Addition of the second linked-list
    return addTwoNumbers(d3, secondList);
}

void solution (node * d1, node * d2){
    // 1. Create a new linked-list to store the resulting values
    node * d3 = NULL;
    // 2. Add the numbers    
    d3 = addNumbers(d1, d2, d3);
    // 3. Display
    display(d3);
}

int main(){
    // 1. Create linked-list
    node * d1 = NULL;
    d1 = insert(3, d1);
    d1 = insert(4, d1);
    d1 = insert(2, d1);

    node * d2 = NULL;
    d2 = insert(4, d2);
    d2 = insert(6, d2);
    d2 = insert(5, d2);
    // d2 = insert(1, d2);
    
    // 3. Display
    printf("List A\t\t\t");
    display(d1);
    printf("\nList B\t\t\t");
    display(d2);
    printf("\n\t\t\t----------\nResulting\t\t");
    solution(d1, d2);
    printf("\nlist");

    return 0;
}