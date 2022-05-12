class Solution {
public:
    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp,int n,int m){
        if(row==n){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int maxi = INT_MAX;
        for(int i = 0; i<m; i++){
            if(i!=col){
                maxi = min(maxi, grid[row][i] + solve(grid, row+1, i, dp,n,m));
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
            ans = min(ans, solve(grid,1,i,dp,n,m) + grid[0][i]);
        }
        return ans;
    }
};