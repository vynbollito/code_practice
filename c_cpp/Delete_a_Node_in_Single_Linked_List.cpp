// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/*
Delete xth node from a singly linked list. 
Your task is to complete the method deleteNode() which
takes two arguments: 
the address of the head of the linked list 
and an integer x. 
The function returns the head of the modified linked list.
    Input:
    2
    3
    1 3 4
    3
    4
    1 5 2 9
    2
    Output:
    1 3
    1 2 9
*/

/* Link list Node */
struct Node{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data){
    struct Node* new_node = new Node(new_data);
    
    if ( *head_ref == NULL ){
       *head_ref = new_node;
    }
    else{
       ( *tail_ref )->next = new_node;
    }
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head){
   while ( head != NULL ){
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T = 0;
  int i = 0;
  int n = 0;
  int l = 0;

    cin>>T;
    while( T-- ){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for( i=1; i<=n; i++ ){
            cin>>l;
            append( &head, &tail, l );
        }
	int kk;
	cin>>kk;
    head = deleteNode(head,kk);
    printList(head);
    }
    return 0;
}
// } Driver Code Ends

/* Link list Node 
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

/*You are required to complete below method*/
// Execution Time:0.01
Node * deleteNode( Node * head, int x ){
    if( head != NULL ){
        struct Node * current = head;
        struct Node * prev = head;
        int count = 1;
        while ( current != NULL ){
            if ( x == 1){
                return current->next;
            }
            if( count == x ){
                prev->next = current->next;
                free(current);
                return head;
            }
            count++;
            prev = current;
            current = current->next;
        }
    }
    return head;
}