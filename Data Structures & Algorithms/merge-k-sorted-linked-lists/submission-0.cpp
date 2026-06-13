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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(ListNode* node : lists){
            if(node) minHeap.push(node);
        }

        ListNode dummy(0);
        ListNode* cur = &dummy;

        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();
            cur->next = node;
            cur = node;
            if(node->next){
                minHeap.push(node->next);
            }
        }
        return dummy.next;
    }
};
