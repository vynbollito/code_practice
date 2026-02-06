// { Driver Code Starts
#include <iostream>
using namespace std;
/*
Given a key (or data) to be inserted into the linked list of size N. 
The task is to insert the element at head or tail of the linked list depending on the input just before it p. 
If p is 0, then insert the element at the beginning else insert at the end.
    Input:
    3
    5
    9 0 5 1 6 1 2 0 5 0
    3
    5 1 6 1 9 1
    4
    15 0 36 0 95 0 14 0
    Output:
    5 2 9 5 6
    5 6 9
    14 95 36 15
*/

/* Struct of linked list */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Function to print list
void printList(Node *head) { 
    Node * node = head;
    while (node != NULL) {
      cout << node -> data << ' ';
      node = node -> next;
    }
    cout << endl;
}

Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);

int main() {
  int test = 0;
  cin >> test; //number of testcases input
  while (test--) { //while we have testcases we run the loop
    int n = 0;
    int ch = 0;
    int tmp = 0;
    Node * head = NULL; //initially head is null as linked list is empty
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
      cin >> tmp >> ch; 
      if (ch) head = insertAtEnd(head, tmp); 
      else head = insertAtBegining(head, tmp);
    }
    printList(head);
  }
  return 0;
}

// } Driver Code Ends

/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Execution Time:0.25
// Keeps track of the last element of the list
Node * lastNode = NULL;
// Function inserts the data in front of the list
Node * insertAtBegining(Node * head, int newData) {
   struct Node * newNode = new Node(newData);
   if ( head != NULL ){
       newNode->next = head;
       return newNode; 
   }
   lastNode = newNode;
   return newNode; 
}

// function appends the data at the end of the list
Node * insertAtEnd(Node * head, int newData)  {
   struct Node * newNode = new Node(newData);
   if ( head != NULL ){
       lastNode->next = newNode;
       lastNode = lastNode->next; 
       return head; 
   }
   lastNode = newNode;
   return newNode;
}