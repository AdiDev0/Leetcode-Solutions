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
    vector<vector<int>> ans;
    void findPaths(TreeNode* root, int targetSum, vector<int> &v, int currSum){
        if(root==NULL) return;
        currSum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL and root->right==NULL){
            if(currSum==targetSum){
                ans.push_back(v);
            }
        }
        findPaths(root->left, targetSum, v, currSum);
        findPaths(root->right, targetSum, v, currSum);
        v.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        findPaths(root,targetSum,v,0);
        return ans;
    }
};