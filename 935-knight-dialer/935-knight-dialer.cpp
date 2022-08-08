class Solution {
public:
    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int mod = 1e9+7;
    
    int solve(int n, vector<vector<int>> &v, int row, int col, vector<vector<vector<int>>> &dp){
        if(n==0) return 1;
        if(dp[row][col][n]!=-1) return dp[row][col][n];
        int count = 0;
        for(int i = 0; i<8; i++){
            int nextR = row + x[i];
            int nextC = col + y[i];
            if(nextR<0 or nextR>=4 or nextC<0 or nextC>=3 or v[nextR][nextC]==-1) continue;
            count = (count + solve(n-1, v, nextR, nextC, dp))%mod;
        }
        return dp[row][col][n] = count;
    }
    int knightDialer(int n) {
        vector<vector<int>> v;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n+1, -1)));
        
        v.push_back({1,2,3});
        v.push_back({4,5,6});
        v.push_back({7,8,9});
        v.push_back({-1,0,-1});
        
        int ans = 0;
        for(int i = 0; i<4; i++){
            for(int j = 0; j<3; j++){
                if(v[i][j]!=-1){
                    ans = (ans + solve(n-1, v, i, j, dp))%mod;
                }
            }
        }
        return ans;
    }
};