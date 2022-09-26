class Solution {
public:
    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = getParent(parent, parent[node]);
    }
    bool equationsPossible(vector<string>& e) {
        int n = e.size();
        vector<int> parent(26, 0);
        vector<int> rank(26,0);
        for(int i = 0; i<26; i++){
            parent[i] = i;
        }
        for(int i = 0; i<n; i++){
            int u = e[i][0]-'a';
            int v = e[i][3]-'a';
            
            int pu = getParent(parent, u);
            int pv = getParent(parent, v);
            
            if(e[i][1]=='='){
                if(rank[pu]<rank[pv]){
                    parent[pu] = pv;
                }
                else if(rank[pu]>rank[pv]){
                    parent[pv] = pu;
                }
                else{
                    parent[pv] = pu;
                    rank[pu]++;
                }
            }
        }
        for(int i = 0; i<n; i++){
            int u = e[i][0]-'a';
            int v = e[i][3]-'a';
            
            int pu = getParent(parent, u);
            int pv = getParent(parent, v);
            
            if(e[i][1]=='!'){
                if(parent[pu]==parent[pv]){
                    return false;
                }
            }
        }
        return true;
    }
};