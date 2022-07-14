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
    TreeNode* solve(vector<int> &pre, vector<int> &in, int preS, int preE, int inS, int inE, unordered_map<int,int> &m){
        if(preS>preE or inS>inE) return NULL;
        
        TreeNode* root = new TreeNode(pre[preS]);
        int ind = m[pre[preS]];
        int d = ind-inS;
        root->left = solve(pre, in, preS+1, preS+d, inS, ind, m);
        root->right = solve(pre, in, preS+d+1, preE, ind+1, inE,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size();
        unordered_map<int,int> m;
        for(int i = 0; i<n; i++){
            m[in[i]] = i;
        }
        return solve(pre, in, 0, n-1, 0, n-1, m);
    }
};