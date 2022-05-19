class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int n,int m,int row, int col){
        // if(row<0 or row>n-1 or col<0 or col>m-1){
        //     return 0;
        // }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int maxi = 1;
        int x[4] = {0,1,0,-1};
        int y[4] = {1,0,-1,0};
        for(int i = 0; i<4; i++){
            int nextRow = row+x[i];
            int nextCol = col+y[i];
            if(nextRow>=0 and nextRow<n and nextCol>=0 and nextCol<m and matrix[nextRow][nextCol]>matrix[row][col]){
                maxi = max(maxi, solve(matrix,dp,n,m,nextRow,nextCol)+1);
            }
        }
        return dp[row][col] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(dp[i][j]==-1){
                    maxi = max(maxi, solve(matrix,dp,n,m,i,j));
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return maxi;
    }
};