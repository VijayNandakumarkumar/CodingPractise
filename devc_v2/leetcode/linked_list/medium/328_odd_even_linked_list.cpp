/*

328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

*/


//Optimal Solution: Nick white

ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        Node odd = head;
        Node even = head->next;
        Node evenHead = even;
        while(even != NULL && even->next!= NULL) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

//Extra space solution

ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
    Node odd = new ListNode();
    Node oddPtr = odd;
    Node even = new ListNode();
    Node evenPtr = even;
    Node p1 = head;
    Node p2 = head->next;
    Node oddLast = NULL;
    while(p1!=NULL || p2 != NULL) {
        if (p1!=NULL) {
            oddPtr->next = new ListNode(p1->val);
            oddPtr = oddPtr->next;
            oddLast = oddPtr;
            if (p1->next != NULL){
                p1 = p1->next->next;
            } else {
                p1 = NULL;
            }
        }
        if (p2!=NULL) {
            evenPtr->next = new ListNode(p2->val);
            evenPtr = evenPtr->next;
            if (p2->next != NULL){
                p2 = p2->next->next;
            } else {
                p2 = NULL;
            }
        }
    }
        
        if (even->next != NULL) {
            oddLast->next = even->next;
            return odd->next;
        } else {
            return odd->next;
        }
        
        
    }
