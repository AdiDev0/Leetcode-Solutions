class Solution {
public:
    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==n-1){
            int maxi = INT_MAX;
            for(int i = 0; i<m; i++){
                if(i!=col){
                    maxi = min(maxi, grid[n-1][i]);
                }
            }
            return dp[row][col] = maxi;
        }
        int maxi = INT_MAX;
        for(int i = 0; i<m; i++){
            if(i!=col){
                maxi = min(maxi, grid[row][i] + solve(grid, row+1, i, dp));
            }
        }
        dp[row][col] = maxi;
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1) return grid[0][0];
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans = INT_MAX;
        
        for(int i = 0; i<n; i++){
            ans = min(ans, solve(grid,1,i,dp) + grid[0][i]);
        }
        return ans;
    }
};