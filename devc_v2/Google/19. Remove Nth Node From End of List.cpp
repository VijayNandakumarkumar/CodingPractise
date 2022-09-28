/*

// Note - 7

19. Remove Nth Node From End of List
Medium

13012

547

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


*/

// Own solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    typedef ListNode* ln;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        } else {
            ln fptr = head;
            ln sptr = head;
            ln prev = NULL;
            for (int i=0; i<n; i++) {
                if (fptr!=NULL) {
                    fptr = fptr->next;
                }
            }
            if (fptr == NULL) {
                head = head->next;
                return head;
            } else {
                while(fptr!=NULL) {
                    prev = sptr;
                    sptr = sptr->next;
                    fptr = fptr->next;
                }
                prev->next = sptr->next;
            }
            return head;
        }
    }
};