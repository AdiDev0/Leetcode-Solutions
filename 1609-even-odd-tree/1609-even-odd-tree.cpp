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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            for(int i = 0; i<n; i++){
                auto temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(level%2!=0){
                for(int i = 0; i<n; i++){
                    if(v[i]%2!=0){
                        return false;
                    }
                    if(i>=1 and v[i]>=v[i-1]){
                        return false;
                    }
                }
            }
            else{
                for(int i = 0; i<n; i++){
                    if(v[i]%2==0){
                        return false;
                    }
                    if(i>=1 and v[i]<=v[i-1]){
                        return false;
                    }
                }
            }
            v.clear();
            level++;
        }
        return true;
    }
};