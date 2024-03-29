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
    string solve(TreeNode* root){
        if(root==NULL) return "";
        string l = solve(root->left);
        string r = solve(root->right);
        
        if(l!="" and r!=""){
            return to_string(root->val)+"("+l+")"+"("+r+")";
        }
        else if(l=="" and r!=""){
            return to_string(root->val)+"()"+"("+r+")";
        }
        else if(l!="" and r==""){
            return to_string(root->val)+"("+l+")";
        }
        return to_string(root->val);
    }
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};