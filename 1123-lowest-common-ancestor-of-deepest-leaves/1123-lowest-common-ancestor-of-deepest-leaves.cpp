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
    int h = 0;
    TreeNode* ans = NULL;
    int solve(TreeNode* root, int currH){
        if(root==NULL) return currH-1;
        
        int l = solve(root->left, currH+1);
        int r = solve(root->right, currH+1);
        
        if(l==r and l>=h){
            h = l;
            ans = root;
        }
        return max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root, 1);
        return ans;
    }
};