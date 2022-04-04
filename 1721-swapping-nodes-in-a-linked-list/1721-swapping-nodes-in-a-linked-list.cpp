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
    ListNode* swapNodes(ListNode* head, int k) {
       vector<ListNode*> v;
       ListNode* p =head;
        while(p!=NULL){
            v.push_back(p);
            p = p->next;
        }
        int n = v.size();
        swap(v[k-1]->val , v[n-k]->val);
        return head;
        
        
    }
};