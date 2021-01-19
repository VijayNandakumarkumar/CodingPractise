/*

2. Add Two Numbers


You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/


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
    typedef struct ListNode* Node;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getListSize(l1);
        int len2 = getListSize(l2);
        Node res = NULL;
        if (len1 >= len2) {
            res = l1;
        } else {
            res = l2;
        }
        
        int sum = 0, carry = 0;
        Node cur1 = l1;
        Node cur2 = l2;
        Node last = NULL;
        while(cur1!=NULL && cur2!=NULL) {
            sum = cur1->val + cur2->val + carry;
            carry = sum/10;
            res->val = sum % 10;
            cur1 = cur1->next;
            cur2 = cur2->next;
            last = res;
            res = res->next;
        }
        
        while((res!=NULL) && (carry != 0)) {
            sum = carry + res->val;
            carry = sum/10;
            sum = sum%10;
            res->val = sum;
            last = res;
            res = res->next;
        }
        if (carry != 0 && last != NULL) {
            ListNode* node = new ListNode(carry);
            last->next = node;
            cout<<"last val "<<last->next->val;
        }
       
        return (len1 >= len2)? l1 : l2;
    }
    int getListSize(Node l)  {
        int size = 0;
        while(l!=NULL) {
            size++;
            l = l->next;
        }
        return size;
    }
    
    Node new_node(int val) {
        Node n = (ListNode*)malloc(sizeof(struct ListNode));
        n->val = val;
        n->next = NULL;
        return n;
    }
    
};
