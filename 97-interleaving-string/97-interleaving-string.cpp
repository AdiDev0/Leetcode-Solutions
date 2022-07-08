class Solution {
public:
    int solve(string &a, string &b, string &c, int n, int m, int k, vector<vector<int>> &dp){
        if(k<0 and n<0 and m<0){
            return 1;
        }
        
        if(n<0 and m>=0 and k>=0){
            if(b[m]==c[k]){
                return solve(a,b,c,n,m-1,k-1,dp);
            }
            return 0;
        }
        if(m<0 and n>=0 and k>=0){
            if(a[n]==c[k]){
                return solve(a,b,c,n-1,m,k-1,dp);   
            }
            return 0;
        }
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        bool ans = false;
        if(a[n]==c[k]){
            ans = ans | solve(a,b,c,n-1,m,k-1,dp);
        }
        if(b[m]==c[k]){
            ans = ans | solve(a,b,c,n,m-1,k-1,dp);
        }
        return dp[n][m] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if(n+m!=k) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s1,s2,s3,n-1,m-1,k-1, dp);
    }
};