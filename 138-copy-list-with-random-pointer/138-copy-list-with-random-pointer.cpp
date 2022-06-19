/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* p = head->next;
        Node* prev = head;
        
        while(prev!=NULL){
            Node* temp = new Node(prev->val);
            prev->next = temp;
            temp->next = p;
            prev = p;
            if(p!=NULL) p = p->next;
        }
        p = head;
        while(p and p->next){
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
        Node* dummy = new Node(-1);
        Node* d = dummy;
        prev = head;
        p = head->next;
        while(prev!=NULL){
            prev->next = p->next;
            d->next = p;
            d = d->next;
            prev = prev->next;
            if(prev) p = prev->next;
        }
        d->next = NULL;
        return dummy->next;
    }
};