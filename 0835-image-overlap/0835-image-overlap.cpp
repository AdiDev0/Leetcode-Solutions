class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> a, b;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(img1[i][j] == 1){
                    a.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    b.push_back({i,j});
                }
            }
        }
        map<pair<int,int>, int> m;
        int ans = 0;
        for(auto i: a){
            for(auto j: b){
                m[{i.first-j.first, i.second- j.second}]++;
                ans = max(ans, m[{i.first-j.first, i.second- j.second}]);
            }
        }
        return ans;
    }
};
