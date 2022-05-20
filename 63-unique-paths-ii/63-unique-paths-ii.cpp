class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i==0 and j==0){
                    dp[i][j] = 1;
                }
                if(i>0){
                    dp[i][j] = dp[i][j] + dp[i-1][j];
                }
                if(j>0){
                    dp[i][j] = dp[i][j] + dp[i][j-1];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};