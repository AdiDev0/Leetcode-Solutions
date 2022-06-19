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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        while(n-- and q!=NULL){
            q = q->next;
        }
        while(q and q->next!=NULL){
            p = p->next;
            q = q->next;
        }
        if(p and p->next){
            ListNode* temp = p->next;
            p->next = temp->next;
            delete(temp);
        }
        return dummy->next;
    }
};