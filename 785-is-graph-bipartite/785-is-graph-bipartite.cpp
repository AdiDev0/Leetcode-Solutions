class Solution {
public:
    bool checkBipartite(vector<int> &vis ,vector<vector<int>>& graph, int node){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            // int n = graph[currNode].size();
            // for(int j = 0; j<n; j++){
            //     if(vis[graph[currNode][j]]==-1){
            //         vis[graph[currNode][j]] = 1 - vis[currNode];
            //         q.push(graph[currNode][j]);
            //     }
            //     else if(vis[graph[currNode][j]] == vis[currNode]){
            //         return false;
            //     }
            // }
            for(auto it: graph[currNode]){
                if(vis[it]==-1){
                    vis[it] = 1 - vis[currNode];
                    q.push(it);
                }
                else if(vis[it] == vis[currNode]){
                    return false;
                }
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n , -1);
        for(int i = 0; i<n ; i++){
            if(vis[i] == -1){
                if(!checkBipartite(vis,graph ,i)){
                    return false;
                }
            }
        }
        return true;
    }
};