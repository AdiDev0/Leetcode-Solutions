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
    int ans = 0;
    void solve(TreeNode* root, vector<int> v){
        if(root==NULL) return;
        v[root->val]++;
        if(root->left==NULL and root->right==NULL){
            int odds = 0;
            for(int i = 1; i<10; i++){
                if(v[i]%2!=0){
                    odds++;
                }
            }
            if(odds<=1) ans++;
            return;
        }
        solve(root->left, v);
        solve(root->right, v);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> v(10, 0);
        solve(root, v);
        return ans;
    }
};