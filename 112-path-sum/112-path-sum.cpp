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
    bool flag = false;
    void solve(TreeNode* root, int t , int currSum){
        if(root==NULL or flag){
            return;
        }
        currSum+=root->val;
        if(!root->left and !root->right){
            if(currSum==t){
                flag = true;
            }
            return;
        }
        solve(root->left , t, currSum);
        solve(root->right , t, currSum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        solve(root,targetSum,0);
        return flag;
    }
};