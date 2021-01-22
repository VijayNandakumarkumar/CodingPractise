/*

Geeks for Geeks: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

Nth node from end of linked list 


Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8.  

*/


int getNthFromLast(Node head, int n){
        Node p = head, f = head;
        for(int i=1; i<=n-1; i++){
            f = f.next;
            if(f == null) return -1;
        }
        while(f.next != null){
            p = p.next;
            f = f.next;
        }
        return p.data;
    }
