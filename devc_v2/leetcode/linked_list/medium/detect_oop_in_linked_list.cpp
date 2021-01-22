/*

Geeks for Geeks: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
Detect Loop in linked list

Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
x = 2
Output: True
Explanation: In above test case N = 3.
The linked list with nodes N = 3 is
given. Then value of x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.

*/

bool isLoopPresent(Node head) {
	Node fast = head;
	Node slow = head;
	while(slow != null && fast != null && fast.next!= null){
		slow = slow.next ;
		fast = fast.next.next;
		if(slow == fast){
			return true;
		}
	}
	return false;
}
