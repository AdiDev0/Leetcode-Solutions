/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        while(p!=NULL or q!=NULL){
            if(p==q){
                return p;
            }
            if(p!=NULL){
                p = p->next;
            }
            else{
                p = headB;
            }
            if(q!=NULL){
                q = q->next;
            }
            else{
                q = headA;
            }
        }
        return NULL;
    }
};