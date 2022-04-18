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
    int count = 0;
    TreeNode *prev = NULL;
    void findNode(TreeNode* root ,int k){
        if(root == NULL){
            return;
        }
        findNode(root->left , k);
        count++;
        if(count == k){
            prev = root;
            return;
        }
        findNode(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        findNode(root , k);
        if(prev == NULL){
            return 0;
        }
        return prev->val;
    }
};