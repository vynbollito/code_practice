// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
Given a linked list of size N, your task is to complete the function isLengthEvenOrOdd()
which contains head of the linked list and check whether the length of linked list 
is even or odd.
    Input:
    2
    3
    9 4 3
    6
    12 52 10 47 95 0
    Output:
    Odd
    Even
*/

struct Node{
	int data;
	struct Node * next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

// Function to check the length of linklist
int isLengthEvenOrOdd( struct Node* head );
	
// Push function
void push( struct Node** head, int info ){
	struct Node* node1 = new Node(info);
	node1->data = info;
	node1->next = (*head);
	(*head) = node1;
}

// Driver function
int main(void){
    int t;
    cin>>t;
    while( t-- ){
        int n = 0;
        int tmp = 0;
        struct Node* head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            push(&head, tmp);
        }
        if( isLengthEvenOrOdd(head) == 0) cout<<"Even\n";
        else cout<<"Odd\n";
    }
	return 0;
}

// } Driver Code Ends

/*structure of a node of the linked list is as
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// Function should return 0 is length is even else return 1
// Execution Time:0.01
int isLengthEvenOrOdd(struct Node* head){
    struct Node * current = head;
    int count = 0;
    
    while(current != NULL){
        count++;
        current = current->next;
    }
    return ( count % 2 );
}