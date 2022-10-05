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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return NULL;
        if(depth==1){
            TreeNode*node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int dep = temp.second;
            if(dep==depth-1){
                // if(node->left){
                    TreeNode* l = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = l;
                // }
                // if(node->right){
                    TreeNode* r = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = r;
                // }
            }
            else{
                if(node->left){
                    q.push({node->left,dep+1});
                }
                if(node->right){
                    q.push({node->right,dep+1});
                }
            }
            
        }
        return root;
        
    }
};