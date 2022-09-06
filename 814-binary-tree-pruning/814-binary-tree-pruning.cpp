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
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(l==0) root->left = NULL;
        if(r==0) root->right = NULL;
        
        if(root->val==1) return l+r+1;
        return l+r;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int val = solve(root); 
        return val==0?NULL:root;
    }
};