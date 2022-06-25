class Solution {
public:
    void solve(vector<int> adj[], vector<int> &vis, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it]==-1){
                solve(adj, vis, it);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i = 0; i<e.size(); i++){
            adj[e[i][0]].push_back(e[i][1]);
            indegree[e[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int> vis(n,-1);
        vector<int> ans;
        for(int i = 0; i<topo.size(); i++){
            int ind = topo[i];
            if(vis[ind]==-1){
                solve(adj,vis,ind);
                ans.push_back(ind);
            }
        }
        return ans;
    }
};