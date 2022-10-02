class Solution {
public:
    int mod = 1e9+7;
    int solve(int n, int k, int t, vector<vector<vector<int>>> &dp){
        if(t<0 or n<0) return 0;
        if(dp[t][n][k]!=-1) return dp[t][n][k];
        if(n==0 and t==0){
            return 1;
        }
        int cnt = 0;
        for(int i = 1; i<=k; i++){
            cnt = cnt + solve(n-1, k, t-i, dp);
            cnt%=mod;
        }
        return dp[t][n][k] = cnt;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        
        return solve(n, k, target, dp);
    }
};