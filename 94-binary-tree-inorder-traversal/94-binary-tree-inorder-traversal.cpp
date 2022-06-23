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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root==NULL) return inorder;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val); // root node is pushed.
                curr = curr->right; 
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=NULL and prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==NULL){ // if we are visiting this node for the first time.
                    prev->right = curr; // a link is made.
                    curr = curr->left;
                }
                else{
                    //prev->right is surely pointing to curr. i.e second visit.
                    prev->right = NULL;
                    inorder.push_back(curr->val); // a subtree's parent is pushed.
                    curr = curr->right; // do the same stuff for right subtree.
                }
            }
        }
        return inorder;
    }
};
// in inorder traversal we are pushing the parent on the second visit but in case of preorder traversal we will push it on our first visit.