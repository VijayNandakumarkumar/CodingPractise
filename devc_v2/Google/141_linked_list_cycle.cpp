/*

141. Linked List Cycle

141. Linked List Cycle
Easy

5964

680

Add to List

Share
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while ((fastPtr != NULL) && (fastPtr->next != NULL)) {
            fastPtr = (fastPtr->next)->next;
            slowPtr = slowPtr->next;
            if ((fastPtr!=NULL) && (fastPtr == slowPtr)) {
                return true;
            }
        }
        return false;
    }
};