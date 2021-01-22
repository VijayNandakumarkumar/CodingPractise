/*

Geeks for Geeks.

Reverse a Linked List in groups of given size.
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.

*/


Node reverseGroup(Node head, int k) {
	int n = 0;
	Node cur = head, prev = NULL, next = NULL;
	while( cur!= NULL && n < k) {
	next = cur->next;
	cur->next = prev;
	prev = cur;
	cur = next;
	}
	if (next != NULL) {
	head->next = reverseGroup(next, k);
	head = prev;
	return head;
	}
}
