#define ll long long

class Solution {
public:
    int mod = 1e9+7;
    int solve(int m, int n, int maxi, int row, int col, vector<vector<vector<ll>>> &dp){
        if(row<0 or row>=m or col<0 or col>=n){
            return 1;
        }
        if(maxi==0) return 0;
        if(dp[row][col][maxi]!=-1) return dp[row][col][maxi]%mod;
        
        ll count = 0;
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nextR = row+x[i];
            int nextC = col+y[i];
            count += solve(m, n, maxi-1, nextR, nextC, dp)%mod;
        }
        return dp[row][col][maxi] = count%mod;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        
        vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>>(n+1, vector<ll>(maxMove+1, -1)));
        int ans = solve(m,n,maxMove, sr, sc, dp)%mod;
        return ans%mod;
    }
};