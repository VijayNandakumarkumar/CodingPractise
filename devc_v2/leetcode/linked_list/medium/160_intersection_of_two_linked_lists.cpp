/*

160 Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

*/

//Optimal Solution: O(2n): Nick white

class Solution {
public:
    typedef struct ListNode* Node;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if (headA == NULL || headB == NULL) {
         return NULL;
     }  
        Node aHead = headA;
        Node bHead = headB;
while(aHead != bHead) {
            if (aHead == NULL) {
                aHead = headB;
            } else {
                aHead = aHead->next;
            }
            
            if (bHead == NULL) {
                bHead = headA;
            } else {
                bHead = bHead->next;
            }
        }
        
     return aHead;   
        
    }
}; 

// Sub optimal solution: O(n2)

class Solution {
public:
    typedef struct ListNode* Node;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if (headA == NULL || headB == NULL) {
         return NULL;
     }  
        Node aHead = headA;
        Node bHead = headB;
        while (headA != NULL) {
            while (headB != NULL) {
               if (headA->val == headB->val) {
                    int temp = headB->val;
                    headB->val = -1;
                    if (headA->val == headB->val) {
                        headB->val = temp;
                        return headB;
                    }
                    headB->val = temp;
                }
                headB = headB->next;
            }
            headB = bHead;
            headA = headA->next;
        }
}
};  
