// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
/*
Given a doubly linked list and a position. 
The task is to delete a node from given position in a doubly linked list. 
    Input:
    2
    3
    1  3 4
    3
    4
    1 5 2 9                    
    1
    Output:
    1 3           
    5 2 9
*/
/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};

void deleteNode(struct Node **head_ref,int temp);

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
   printf("\n");
}
 
/* Drier program to test above functions*/
int main()
{
  int t, x, n, i;
  scanf("%d",&t);
  
  while(t--)
  {
      /* Start with the empty list */
      struct Node *temp,*head = NULL;
      scanf("%d",&n);
      
      temp = NULL;
      
      for(i=0;i<n;i++){
        scanf("%d",&x);
        
        if(head == NULL){
            head = new Node(x);
            temp = head;
        }
        else{
            Node *temp1 = new Node(x);
            temp->next = temp1;
            temp1->prev = temp;
            temp = temp->next;
        }
      }
  
    scanf("%d",&x);
      
    deleteNode(&head,x);  /*delete first Node*/  
      
        /* Modified linked list will be NULL<-8->NULL */
        printList(head);           
        while(head->next!=NULL)
        {
    	    temp=head;
    	    head=head->next;
    	    free(temp);
    	}
    	
    	free(head);
	}
	return 0;
}
// } Driver Code Ends


/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

// Function to delete the node at position x
// Execution Time:0.02
void deleteNode(Node **head_ref, int x){
    struct Node * current = * head_ref;
    if( current != NULL ){
        if ( x == 1){
            current->prev = NULL;
            *head_ref = current->next;
            return; 
        }
        int count = 1;
        while ( current != NULL ){
            if( count == x ){
                current->prev->next = current->next;
                if ( current->next != NULL ){
                    current->next->prev = current->prev;
                }
                free(current);
                return;
            }
            count++;
            current = current->next;
        }
    }
}