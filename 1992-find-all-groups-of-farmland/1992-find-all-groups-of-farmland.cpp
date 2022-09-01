class Solution {
public:
    int n;
    int m;
    void solve(vector<vector<int>> &land, int row, int col, int &mini, int &minj, int &maxi, int &maxj){
        mini = min(mini, row);
        minj = min(minj, col);
        maxi = max(maxi, row);
        maxj = max(maxj, col);
        
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        
        for(int i = 0; i<4; i++){
            int nr = row+x[i];
            int nc = col+y[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and land[nr][nc]==1){
                land[nr][nc] = 0;
                solve(land, nr, nc, mini, minj, maxi, maxj);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>> ans;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(land[i][j]==1){
                    int mini = i, maxi = i, minj = j, maxj = j;
                    solve(land, i, j, mini, minj, maxi, maxj);
                    ans.push_back({mini, minj, maxi, maxj});
                }
            }
        }
        return ans;
    }
};