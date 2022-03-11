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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        ListNode *p = head;
        ListNode *q = head;
        int count = 0;
        ListNode *c = head;
        while(c!=NULL){
            c = c->next;
            count++;
        }
        if(k==0 or count==k){
            return head;
        }
        else if(count < k){
            k = k%count;
        }
        
        int i = 0;
        while(i<k){
            p = p->next;
            i++;
        }
        while(p->next!=NULL){
            q = q->next;
            p = p->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};