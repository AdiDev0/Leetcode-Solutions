class Solution {
public:
    int solve(string &a, string &b, int n, int m, vector<vector<int>> &dp){
        if(n<0 or m<0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        int pickN = 0, pickM = 0, pickBoth = 0;
        if(a[n]==b[m]){
            pickBoth = 1 + solve(a,b,n-1,m-1, dp);
        }
        else{
            pickN = solve(a,b,n-1,m, dp);
            pickM = solve(a,b,n,m-1, dp);
        }
        return dp[n][m] = max({pickBoth, pickN, pickM});
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(s1, s2, n-1, m-1, dp);
    }
};