class Solution {
public:
    int dfs(int root, vector<int> &l, vector<int> &r){
        if(root==-1) return 0;
        
        int left = dfs(l[root], l, r);
        int right = dfs(r[root],l,r);
        
        return left+right+1;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r){
        unordered_map<int,int> m;
        int edges = 0;
        for(int i = 0; i<n; i++){
            if(l[i]!=-1){
                if(m[l[i]]){
                    return false;
                }
                else{
                    m[l[i]] = i;
                    edges++;
                }
            }
            if(r[i]!=-1){
                if(m[r[i]]){
                    return false;
                }
                else{
                    m[r[i]] = i;
                    edges++;
                }
            }
        }
        int root = -1;
        for(int i = 0; i<n; i++){
            if(m.find(i)==m.end()){
                root = i;
                break;
            }
        }
        if(root==-1) return false;
        
        int nodes = dfs(root, l, r);
        
        if(nodes!=n) return false;
        return edges==n-1;
    }
};