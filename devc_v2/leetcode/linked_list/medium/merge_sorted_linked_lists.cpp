/*

GeeksForGeeks: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,]
10, 15, 20, 40.

*/


#include<bits/stdc++.h>
using namespace std;

int mergeSortedlists(Node h1, Node h2) 
{ 
    if (h1 == NULL || h2 == NULL) 
        return (h1 == NULL) ? h2: h1; 
    Node h = h1;
  
    while(h1 != NULL && h2!= NULL) {
        if (h1->data < h2->data) {
            h1 = h1->next;
        } else {
            Node temp = h2;
            h2 = h2->next;
            temp->next = h1->next;
            h1->next = temp;
            int tempVal = temp->data;
            temp->data = h1->data;
            h1->data = tempVal;
            h1 = h1->next;
        }
    }
    if (h1 == NULL && h2 == NULL) {
        
    } else if (h1->next == NULL) {
        h1->next = h2;
    }
    return h;
    
} 
