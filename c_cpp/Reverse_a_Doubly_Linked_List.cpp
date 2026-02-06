// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
/*
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.
    Input:
    2
    3
    3 4 5
    8
    75 122 59 196 30 38 36 194
    Output:
    5 4 3
    194 36 38 30 196 59 122 75
*/
struct Node{
    int data;
    Node * next;
    Node * prev;
    Node (int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
        
};

Node * newNode(int data){
    Node *temp=new Node(data);
    return temp;
}

Node * addNode(Node * head, int data){
    if( head == NULL ){
        return newNode(data);
    }
    else{
        Node * temp = head;
        Node * prev = head;
        while( temp->next ){
            prev = temp;
            temp = temp->next;
        }
        temp->next = newNode(data);
        prev = temp;
        temp = temp->next;
        temp->prev = prev;
        return head;
    }
}

void displayList(Node * head){
    //Head to Tail
    while( head->next ){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data;
}

int getLength(Node * head){
    Node * temp = head;
    int count = 0;
    while( temp->next != head ){
        count++;
        temp = temp->next;
    }
    return count+1;
}

bool verify(Node * head){
    int fl = 0;
    int bl = 0;
    
    Node * temp = head;
    while( temp->next ){
        temp = temp->next;
        fl++;
    }
    while( temp->prev ){
        temp = temp->prev;
        bl++;
    }
    return fl == bl;
}

 // } Driver Code Ends
/*
struct Node{
    int data;
    Node * next;
    Node * prev;
    Node (int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/
/*
// Execution Time:0.03
Node * reverseDLL( Node * head ){
    if ( head != NULL ){
        Node * current = head;
        Node * aux = NULL;
        
        while ( current != NULL ){
            aux = current->prev;
            current->prev = current->next;
            current->next = aux;
            if (current->prev == NULL ){ 
                return current;
            }
            current = current->prev;
        }
        return current;
    }
    return head;
}
*/
// Execution Time:0.02
Node* reverseDLL(Node * head){
    Node * current = head;
    Node * aux = NULL;
    
    while ( current != NULL ){
        aux = current->prev;
        current->prev = current->next;
        current->next = aux;
        if ( current->prev == NULL ){ 
            return current;
        }
        current = current->prev;
    }
    return current;
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while( t-- ){
	    int n;
	    cin>>n;
	    Node * head=NULL;
	    for( int i = 0; i < n; i++ ){
	        int x;
	        cin>>x;
	        head = addNode( head, x );
	    }
	    head = reverseDLL( head );
	    
	    if( verify( head ) )
	        displayList( head );
	    else
	        cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends