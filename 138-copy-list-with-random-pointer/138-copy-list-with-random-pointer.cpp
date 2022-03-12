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
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            Node* temp = new Node(head->val);
            temp->next = NULL;
            if(head->random){
               temp->random = temp; 
            }
            else{
                temp->random = NULL;
            }
            return temp;
        }
        Node* p = head->next;
        Node* prev = head;
        while(p!=NULL){
            Node* temp = new Node(prev->val);
            prev->next = temp;
            temp->next = p;
            prev = p;
            p = p->next;
            if(p==NULL){
                Node* temp = new Node(prev->val);
                prev->next = temp;
                prev = prev->next;
                prev->next = p;
            }
        }
        prev = head;
        p = head->next;
        while(p->next!=NULL){
            if(prev->random){
                p->random = prev->random->next;
            }
            else{
                p->random = NULL;
            }
            p = p->next->next;
            prev = prev->next->next;
            if(p->next==NULL){
                if(prev->random){
                    p->random = prev->random->next;
                }
                else{
                    p->random = NULL;
                }
            }
        }
        prev = head;
        p = head->next;
        Node* head1 = NULL;
        Node* q = NULL;
        while(p!=NULL){
            prev->next = p->next;
            if(head1==NULL){
                q = p;
                head1 = q;
            }
            else{
                q->next = p;
                q = q->next;
            }
            prev = prev->next;
            if(prev){
                p = prev->next;
            }
            else{
                break;
            }
        }
        q->next = NULL;
        return head1;
    }
};