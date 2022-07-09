class Solution {
public:
    vector<int> h;
    vector<vector<int>> cost;
    int target = 0;
    int solve(int m, int n, int k, int i,int lastC, vector<vector<vector<int>>> &dp){
        
        if(i==m){
            if(k==target) return 0;
            return 1e7+1;
        }
        if(k>target) return -1;
        
        if(dp[i][lastC][k]!=-1) return dp[i][lastC][k];
        
        int ans = 1e7+1;
        if(h[i]!=0){
            if(lastC==h[i]){
                ans = solve(m,n,k,i+1,h[i],dp);
            }
            else{
                ans = solve(m,n,k+1,i+1,h[i],dp);
            }
        }
        else{
            for(int j = 0; j<n; j++){
                int val;
                if(j+1==lastC){
                    val = solve(m,n,k,i+1,j+1,dp);
                }
                else{
                    val = solve(m,n,k+1,i+1,j+1,dp);
                }
                if(val!=-1){
                    ans = min(ans, val+cost[i][j]);
                }
            }
        }
        return dp[i][lastC][k] = ans;
    }
    int minCost(vector<int> &house, vector<vector<int>> &c, int m, int n, int t) {
        h = house;
        cost = c;
        target = t;
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(target+1,-1)));
        int ans = solve(m, n, 0,0,0,dp);
        return ans==1e7+1?-1:ans;
    }
};