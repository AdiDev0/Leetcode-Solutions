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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *result = new ListNode(-1);
        ListNode *temp = result;
        int carry = 0;
        vector<int> v;
        while(p!=NULL and q!=NULL){
            int currSum = p->val+q->val+carry;
            if(currSum > 9){
                result->next = new ListNode(currSum%10);
                result = result->next;
                carry = currSum/10;
            }
            else{
                result->next = new ListNode(currSum);
                result = result->next;
                carry = 0;
            }
            p = p->next;
            q = q->next;
        }
        while(p!=NULL ){
            int currSum = p->val + carry;
            if(currSum>9){
                result->next = new ListNode(currSum%10);
                result = result->next;
                carry = currSum/10;
            }
            else{
                result->next = new ListNode(currSum);
                result = result->next;
                carry = 0;
            }
            p = p->next;
        }
        while(q!=NULL){
            int currSum = q->val + carry;
            if(currSum>9){
                result->next = new ListNode(currSum%10);
                result = result->next;
                carry = currSum/10;
            }
            else{
                result->next = new ListNode(currSum);
                result = result->next;
                carry = 0;
            }
            q = q->next;
        }
        if(carry>0){
            result->next = new ListNode(carry);
        }
        result = temp->next;
        delete temp;
        return result;
    }
};