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
    int countNodes(TreeNode* root) {
        if(root!=NULL){
            int leftH = 0;
            int rightH = 0;
            TreeNode* leftNode = root;
            TreeNode* rightNode = root;
            while(leftNode){
                leftNode = leftNode->left;
                leftH++;
            }
            while(rightNode){
                rightNode = rightNode->right;
                rightH++;
            }
            if(leftH==rightH){
                return pow(2,leftH) - 1;
            }
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
        return 0;
    }
};