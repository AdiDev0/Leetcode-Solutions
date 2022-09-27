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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* prev = NULL;
        ListNode* ans = NULL;
        
        while(p!=NULL and p->next!=NULL){
            q = p->next;
            p->next = q->next;
            q->next = p;
            if(prev==NULL){
                ans = q;
                prev = p;
            }
            else{
                prev->next = q;
                prev = p;
            }
            p = p->next;
        }
        return ans;
    }
};