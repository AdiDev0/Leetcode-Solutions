class Solution {
public:
    void solve( vector<int> adj[], int node, int &cnt, vector<int> &vis){
        vis[node] = 1;
        cnt++;
        for(auto it: adj[node]){
            if(vis[it]==-1){
                solve(adj, it, cnt, vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& e) {
        vector<int> adj[n];
        for(int i = 0; i<e.size(); i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        
        vector<int> vis(n, -1);
        vector<long long> v;
        for(int i = 0; i<n; i++){
            if(vis[i]==-1){
                int cnt = 0;
                solve(adj, i, cnt, vis);
                v.push_back(cnt);
            }
        }
        vector<long long> pre(n,0);
        pre[0] = v[0];
        for(int i = 1; i<v.size(); i++){
            pre[i]+=pre[i-1]+v[i];
        }
        long long ans = 0;
        for(int i = 1; i<v.size(); i++){
            ans += (long long)v[i]*pre[i-1];
        }
        
        return ans;
    }
};