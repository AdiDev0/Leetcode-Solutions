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
    TreeNode* head = NULL;
    TreeNode* prev = NULL;
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        if(prev == NULL){
            prev = root;
        }
        else{
            prev->right = root;
            root->left = NULL;
        }
        if(head == NULL) head = root;
        prev = root;
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        return head;
    }
};