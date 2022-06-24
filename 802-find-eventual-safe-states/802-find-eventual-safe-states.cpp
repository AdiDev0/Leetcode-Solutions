class Solution {
public:
    unordered_map<int,int> dfs;
    bool solve(vector<int> adj[], vector<int> &vis, vector<bool> &ans, int node){
        vis[node] = 1;
        dfs[node]++;
        for(auto it: adj[node]){
            if(vis[it]==-1){
                bool val = solve(adj, vis, ans, it);
                if(!val){
                    return ans[node] = val;   
                }
            }
            else if(vis[it]==1 and dfs[it]>=1){
                return ans[node] = false;
            }
        }
        dfs.erase(node);
        return ans[node] = true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graphs) {
        int n = graphs.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++){
            for(auto it: graphs[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> vis(n, -1);
        vector<bool> ans(n, false);
        
        for(int i = 0; i<n; i++){
            if(vis[i]==-1){
                solve(adj, vis, ans, i);
            }
        }
        vector<int> v;
        for(int i = 0; i<n; i++){
            if(ans[i]){
                v.push_back(i);
            }
        }
        return v;
    }
};