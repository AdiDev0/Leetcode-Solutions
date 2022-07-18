
class Solution {
public:
    
    void dfs(vector<int> adj[], int node, vector<int> &subtreeCnt, vector<int> &subtreeRes, int parent){
        for(auto it: adj[node]){
            if(it==parent) continue;
            dfs(adj, it, subtreeCnt,subtreeRes, node);
            subtreeCnt[node] += subtreeCnt[it]; 
            subtreeRes[node] += subtreeRes[it] + subtreeCnt[it];
        }
        subtreeCnt[node] += 1;  //the node itself is added to the count;
    }
    void dfs2(vector<int> adj[], int node, vector<int> &subtreeCnt, vector<int> &subtreeRes, int parent){
        for(auto it: adj[node]){
            if(it==parent) continue;
            subtreeRes[it] = subtreeRes[node] - subtreeCnt[it] + subtreeCnt.size() - subtreeCnt[it];
            dfs2(adj, it, subtreeCnt,subtreeRes,node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> subtreeCnt(n, 0);
        vector<int> subtreeRes(n, 0);
        
        dfs(adj, 0, subtreeCnt, subtreeRes, -1);
        dfs2(adj, 0, subtreeCnt, subtreeRes, -1);
        return subtreeRes;
    }
};