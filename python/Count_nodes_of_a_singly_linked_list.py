# User function Template for python3
'''
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

Your task is to return the count of elements
in the given linked list

Function Arguments: head_node (head of the linked list)
Return Type: Integer

	Contributed By: Nagendra Jha
	
Given a singly linked list.
The task is to find the length of the linked list, 
where length is defined as the number of nodes in the linked list.
    Input:
    2
    5
    1 2 3 4 5
    7
    2 4 6 7 5 1 0
    Output:
    5
    7
	
'''
# Execution Time:0.76
def getCount(head_node):
    #code here
    current = head_node
    sum = 0
    while current != None:
        sum = sum + 1
        current = current.next
    return sum

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import io
import sys

    
# Node class
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
#Linked list class
class LinkedList:
    def __init__(self):
        self.head=None
        self.tail=None

    # append at the end of the list
    def append(self,new_node):
        if self.head is None:
            self.head=new_node
            self.tail=new_node
            return
        self.tail.next=new_node
        self.tail = self.tail.next

if __name__ == '__main__':
    t=int(input())
    for cases in range(t):
        n=int(input())
        a=LinkedList()
        nodes=list(map(int,input().strip().split())) #list containing nodes
        for x in nodes:
            node=Node(x) # create a new node
            a.append(node)
        print(getCount(a.head))
# } Driver Code Ends