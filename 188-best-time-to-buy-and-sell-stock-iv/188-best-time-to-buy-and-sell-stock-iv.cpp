class Solution {
public:
    int solve(vector<int> &p, int k, int buy, int ind, vector<vector<int>> &dp){
        if(ind==p.size()-1){
            return max(p[ind]-p[buy],0);
        }
        if(k<=0) return 0;
        if(dp[buy][k]!=-1) return dp[buy][k];
        int profit = 0;
        if(p[ind]>p[buy]){
            int a = p[ind]-p[buy] + solve(p, k-1, ind, ind+1, dp);
            int b = solve(p, k, buy, ind+1, dp);
            profit = max(a,b);
        }
        else{
            int c = solve(p, k, ind, ind+1, dp);
            profit = c;
        }
        return dp[buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        int ans = solve(p, k, 0, 0, dp);
        return ans;
    }
};