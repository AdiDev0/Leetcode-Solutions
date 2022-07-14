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
    vector<TreeNode*> ans;
    TreeNode* solve(TreeNode* root, unordered_map<int,int> &m){
        
        if(root==NULL) return NULL;
        
        TreeNode* l = solve(root->left, m);
        TreeNode* r = solve(root->right, m);
        if(l and l->val==-1) root->left = NULL;
        if(r and r->val==-1) root->right = NULL;
        if(m[root->val]){
            if(l and l->val!=-1){
                ans.push_back(l);
            }
            if(r and r->val!=-1){
                ans.push_back(r);
            }
            return new TreeNode(-1);
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        unordered_map<int,int> m;
        for(auto it: del) m[it]++;
        TreeNode* r = solve(root, m);
        if(!m[r->val] and r->val!=-1) ans.push_back(r);
        return ans;
    }
};