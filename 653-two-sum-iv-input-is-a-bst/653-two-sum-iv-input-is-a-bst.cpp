/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTiterator{
    private:
    void pushAll(TreeNode* root){
        if(reversed){
            TreeNode* temp = root->left;
            while(temp!=NULL){
                s.push(temp);
                temp = temp->right;
            }
        }
        else{
            TreeNode* temp = root->right;
            while(temp!=NULL){
                s.push(temp);
                temp = temp->left;
            }
        }
    }
    public:
    stack<TreeNode*> s;
    bool reversed = true;
    BSTiterator(TreeNode* root, bool isReversed){
        reversed = isReversed;
        if(reversed){
            while(root!=NULL){
                s.push(root);
                root = root->right;
            }
        }
        else{
            while(root!=NULL){
                s.push(root);
                root = root->left;
            }
        }
    }
    
    bool hasNext(){
        return s.size()>0;
    }
    int isNext(){
        TreeNode* temp = s.top();
        s.pop();
        
        if(reversed){
            if(temp->left){
                pushAll(temp);
            }
        }
        else{
            if(temp->right){
                pushAll(temp);
            }
        }
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTiterator nex(root, false);  // for next iterator.
        BSTiterator bef(root, true);   // for before iterator.
        
        int i = nex.isNext();
        int j = bef.isNext();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i = nex.isNext();
            }
            else{
                j = bef.isNext();
            }
        }
        return false;
    }
};