class Solution {
public:
    int solve(int n, int m, int row, int col, vector<vector<int>> &dp){
        if(row==n-1 and col==m-1){
            return 1;
        }
        if(row>=n or col>=m){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int val = solve(n,m,row,col+1,dp) + solve(n,m,row+1,col,dp);
        return dp[row][col] = val;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n,m,0,0,dp);
    }
};