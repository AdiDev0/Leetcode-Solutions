class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        int n = a.size();
        int m = b.size();
        if(i==n and j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n){
            return dp[i][j] = m-j;
        }
        if(j==m){
            return dp[i][j] = n-i;
        }
        int del = 0, rep = 0, ins = 0;
        if(a[i]==b[j]){
            return dp[i][j] = solve(a,b,i+1,j+1,dp);
        }
        else{
            del = solve(a,b,i+1,j,dp);
            rep = solve(a,b,i+1,j+1,dp);
            ins = solve(a,b,i,j+1,dp);
        }
        return dp[i][j] = min({del,rep,ins})+1;
    }
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(a,b,0,0,dp);
    }
};