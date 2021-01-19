

/*

Geeks for Geeks: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#companyTags

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

*/

//Solution: We can swap the list nodes -> push the nodes with value 2 to last and with value 0 to head, nodes with value 1 will be in middle.

//Solution: https://ide.geeksforgeeks.org/CyuC4m
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  class Node {
 int value;
  Node next;

  Node(int value) {
   this.value = value;

  }

}

*/
class GFG
{
    void linksort(Node head)
    {
        int n0 = 0, n1 = 0, n2 = 0;
        Node crr = head;
        while (crr != null) {
            if (crr.value == 0) {
                n0++;
            } else if (crr.value == 1) {
                n1++;
            } else {
                n2++;
            }
            crr = crr.next;
        }
        crr = head;
        while (n0-- > 0) {
            crr.value = 0;
            crr = crr.next;
        }
        while (n1-- > 0) {
            crr.value = 1;
            crr = crr.next;
        }
        while (n2-- > 0) {
            crr.value = 2;
            crr = crr.next;
        }
    }
}
