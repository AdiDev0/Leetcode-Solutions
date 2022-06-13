class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        for(int i = 1; i<n; i++){
            int m = tri[i].size();
            for(int j = 0; j<m; j++){
                if(j==0){
                    tri[i][j] += tri[i-1][j];
                }
                else if(j==m-1){
                    tri[i][j] += tri[i-1][j-1];
                }
                else{
                    tri[i][j] += min(tri[i-1][j], tri[i-1][j-1]);
                }
            }
        }
        int maxi = INT_MAX;
        for(int k = 0; k<tri[n-1].size(); k++){
            maxi = min(maxi, tri[n-1][k]);
        }
        return maxi;
    }
};