class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(j==p.size()) return i==s.size();
        if(i==s.size() and j<p.size()){
            if(p[j]=='*'){
                return dp[i][j] = solve(s,p,i,j+1,dp);
            }
            return dp[i][j] = 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]=='*'){
            bool usingAsterisk = solve(s,p,i+1,j,dp);
            bool notUsingAsterisk = solve(s,p,i,j+1,dp);
            return dp[i][j] = usingAsterisk or notUsingAsterisk;
        }
        else if(s[i]==p[j] or p[j]=='?'){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return solve(s, p, 0, 0, dp);
    }
};