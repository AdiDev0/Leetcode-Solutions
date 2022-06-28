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
    bool ans = false;
    string solveSub(TreeNode* root){
        if(root==NULL) return "#";
        string l = solveSub(root->left);
        string r = solveSub(root->right);
        
        return "#"+l+to_string(root->val)+r+"#";
    }
    string solve(TreeNode* root, string &s){
        if(ans) return "";
        if(root==NULL) return "#";
        string l = solve(root->left, s);
        string r = solve(root->right, s);
        string str = "#"+l+to_string(root->val)+r+"#";
        if(str == s) ans = true;
        return str;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string a = solveSub(subRoot);
        string b = solve(root, a);
        return ans;
    }
};