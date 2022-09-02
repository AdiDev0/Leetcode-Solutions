class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        
        vector<int> adj[n], back[n];
        for(int i = 0; i<conn.size(); i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            back[conn[i][1]].push_back(conn[i][0]);
        }
        
        queue<int> q;
        vector<int> vis(n, -1);
        int ans = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto it: adj[node]){
                if(vis[it]==-1){
                    ans++;
                    q.push(it);
                }
            }
            for(auto it: back[node]){
                if(vis[it]==-1){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};


// 1---->2---->0