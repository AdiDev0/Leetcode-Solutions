class Solution {
public:
    int n;
    int m;
    void solve(vector<vector<int>> &land, int row, int col, int &maxR, int &maxC){
        maxR = max(maxR, row);
        maxC = max(maxC, col);
        
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        
        for(int i = 0; i<4; i++){
            int nr = row+x[i];
            int nc = col+y[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and land[nr][nc]==1){
                land[nr][nc] = 0;
                solve(land, nr, nc, maxR, maxC);
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
                    int maxR = i, maxC = j;
                    solve(land, i, j, maxR, maxC);
                    ans.push_back({i,j, maxR, maxC});
                }
            }
        }
        return ans;
    }
};