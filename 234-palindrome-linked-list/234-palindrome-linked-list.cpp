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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout<<slow->val<<endl;
        ListNode* prev = NULL;
        ListNode* current = slow->next;
        ListNode* nextOne = NULL;
        while(current){
            nextOne = current->next;
            current->next = prev;
            prev = current;
            current = nextOne;
        }
        ListNode* secondHead = prev;
        ListNode* p = head;
        ListNode* q = prev;
        while(q){
            if(p->val!=q->val){
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};