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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list = reverse(slow->next);
        ListNode*p = head;
        while(list!=NULL){
            if(list->val!=p->val) return false;
            list = list->next;
            p = p->next;
        }
        return true;
    }
};