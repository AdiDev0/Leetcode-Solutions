class Solution {
public:
    int getParent(int p, vector<int> &parent){
        if(parent[p]==p){
            return p;
        }
        return parent[p] = getParent(parent[p], parent);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int> parent, rank;
        
        for(int i = 0; i<n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        
        vector<vector<int>> v;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int a = abs(points[i][0]-points[j][0]);
                int b = abs(points[i][1]-points[j][1]);
                v.push_back({a+b, i, j});
            }
        }
        
        sort(v.begin(), v.end());
        
        int ans = 0;
        for(auto it: v){
            auto a = getParent(it[1], parent);
            auto b = getParent(it[2], parent);
            if(a!=b){
                ans += it[0];
                if(rank[a]<rank[b]){
                    parent[a] = b;
                }
                else if(rank[a]>rank[b]){
                    parent[b] = a;
                }
                else{
                    parent[a] = b;
                    rank[a]++;
                }
            }
        }
        return ans;
    }
};