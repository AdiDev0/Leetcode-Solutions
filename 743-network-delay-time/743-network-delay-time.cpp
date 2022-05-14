class Solution {
public:
    void dfs(vector<pair<int,int>> adj[], int src, vector<int> &vis){
        for(auto it: adj[src]){
            int node = it.first;
            int dist = it.second;
            if(vis[node]> vis[src] + dist or vis[node]==-1){
                vis[node] = vis[src] + dist;
                dfs(adj, node, vis);
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i = 0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> vis(n+1,-1);
        vis[k] = 0;
        dfs(adj, k, vis);
        int ans = 0;
        for(int i = 1;i<=n; i++){
            if(vis[i]==-1) return -1;
            ans = max(ans, vis[i]);
        }
        return ans;
    }
};