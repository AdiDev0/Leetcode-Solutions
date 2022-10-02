class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i+2<n and j+2<m){
                    int val = grid[i][j] + grid[i][j+1] + grid[i][j+2]+grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                    maxi = max(maxi, val);
                }
            }
        }
        return maxi;
    }
};