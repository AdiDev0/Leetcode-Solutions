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

// 1 -> need camera
// 2 -> camera present
// 0 -> no need

class Solution {
public:
    int cnt = 0;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l==1 or r==1){
            cnt++;
            return 2;
        }
        else if(l==2 or r==2){
            return 0;
        }
        else{
            return 1;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        if(solve(root) == 1) cnt++;
        return cnt;
    }
};