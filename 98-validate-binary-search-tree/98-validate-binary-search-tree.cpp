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
    bool solve(TreeNode* root, TreeNode* mini, TreeNode* maxi){
        if(root == NULL) return true;
        bool l = false;
        bool r = false;
        if(mini==NULL or mini->val > root->val){
            l = solve(root->left, root, maxi);
        }
        if(maxi==NULL or maxi->val < root->val){
            r = solve(root->right, mini, root);
        }
        return l and r;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};