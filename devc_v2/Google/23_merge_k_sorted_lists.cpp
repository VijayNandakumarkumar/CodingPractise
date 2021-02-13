/*

23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

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
    typedef struct ListNode* LNode;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        auto comp = [] (pair<LNode, int> a, pair<LNode, int> b) {
            return a.first->val > b.first->val;
        };
        
        priority_queue<pair<LNode, int>, vector<pair<LNode, int>>, decltype(comp)> q(comp);
        vector<LNode> headPtrs(lists.size());
        for (int i = 0; i<lists.size(); i++) {
            if (lists[i]!=NULL) {
                headPtrs[i] = lists[i];
                q.push({headPtrs[i], i});
            }
        }
        if (q.empty()) {
            return NULL;
        }
        pair<LNode, int> topPair = q.top();
        q.pop();
        
        LNode head = topPair.first;
        LNode tail = topPair.first;
        
        int idx = topPair.second;
        cout<<idx<<" "<<head->val<<"\n";
        headPtrs[idx] = headPtrs[idx]->next;
        if (headPtrs[idx] != NULL) {
           q.push({headPtrs[idx], idx});
        }
        while(!q.empty()) {
            topPair = q.top();
            q.pop();
            
            tail->next = topPair.first;
            tail = tail->next;
            
            idx = topPair.second;
            headPtrs[idx] = headPtrs[idx]->next;
            if (headPtrs[idx] != NULL) {
                q.push({headPtrs[idx], idx});
            }
        }
        return head;
    }
};
