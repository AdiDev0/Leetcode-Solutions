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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        auto a = solve(root->left);
        auto b = solve(root->right);
        
    // from left child we need ans for its right;
        int aright = a.second;
        
    // from right child we need ans for its left;    
        int bleft = b.first;
                
        ans = max({ans, aright+1, bleft+1});
        return {aright+1, bleft+1};
    }
    int longestZigZag(TreeNode* root) {
        auto a = solve(root);
        return ans-1;
    }
};