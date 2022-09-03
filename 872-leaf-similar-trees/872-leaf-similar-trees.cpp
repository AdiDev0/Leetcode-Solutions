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
    vector<int> a, b;
    void getLeaves1(TreeNode*root){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            a.push_back(root->val);
        }
        getLeaves1(root->left);
        getLeaves1(root->right);
    }
    void getLeaves2(TreeNode*root){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            b.push_back(root->val);
        }
        getLeaves2(root->left);
        getLeaves2(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaves1(root1);
        getLeaves2(root2);
        return a==b;
    }
};