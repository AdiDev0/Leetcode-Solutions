class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0]<=b[0];
    }
    int getParent(int p, unordered_map<int, int> &parent){
        if(parent[p]==p){
            return p;
        }
        return parent[p] = getParent(parent[p], parent);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        for(int i = 0; i<n; i++){
            rank[i] = 0;
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
        // for(auto it: v){
        //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        // }
        int ans = 0;
        for(auto it: v){
            auto a = getParent(it[1], parent);
            auto b = getParent(it[2], parent);
            // cout<<a<<endl;
            // cout<<b<<endl;
            // cout<<endl;
            
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

// [[3,12],[-2,5],[-4,1]]


// 6 [-2,5],[-4,1]
// 12  [3,12],[-2,5]
// 18 [3,12],[-4,1]
