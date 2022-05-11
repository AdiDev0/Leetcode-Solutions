class Solution {
public:
    int solve(vector<vector<int>>& grid, int row,int col,int n, int m,vector<vector<int>> &dp){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(row==n-1 and col==m-1){
            return dp[row][col] =  grid[row][col];
        }
        if(row==n-1 and col<m-1){
            return dp[row][col] = grid[row][col] + solve(grid,row,col+1,n,m,dp);
        }
        if(col==m-1 and row<n-1){
            return dp[row][col] = grid[row][col] + solve(grid,row+1,col,n,m,dp);
        }
        int rightSum = solve(grid,row,col+1,n,m,dp);
        int downSum = solve(grid,row+1,col,n,m,dp);
        return dp[row][col] = grid[row][col] + min(rightSum, downSum);
    }
    int minPathSum(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(grid,0,0,n,m,dp);
    }
};