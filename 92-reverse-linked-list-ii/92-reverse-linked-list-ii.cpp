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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        int count = 1;
        while(count<left){
            count++;
            p = p->next;
        }
        count = 1;
        while(count<=right){
            count++;
            q = q->next;
        }
        ListNode* qnext = NULL;
        if(q) qnext = q->next;
        ListNode* prev = NULL;
        ListNode* nextOne = NULL;
        ListNode* curr = p->next;
        ListNode* first = p->next;
        p->next = NULL;
        if(qnext!=NULL){
            while(curr!=qnext){
                nextOne = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextOne;
            }
        }
        else{
            while(curr!=NULL){
                nextOne = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextOne;
            }
        }
        p->next = prev;
        if(first) first->next = qnext;
        return dummy->next;
    }
};