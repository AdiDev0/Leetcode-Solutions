class Solution {
public:
    int solve(vector<int> &p, int k, int buy, int ind, vector<vector<int>> &dp){
        if(ind==p.size()){
            return dp[buy][k] = 0;
        }
        if(k<=0) return dp[buy][k] = 0;
        if(dp[buy][k]!=-1) return dp[buy][k];
        
        int currProfit = 0;
        
        if(p[ind]>p[buy]){
            //if curr price is greater than the price at which stock was bought
            //we have two options
            //a. either sell today
            //b. keep the stock
            int sellToday = p[ind]-p[buy] + solve(p, k-1, ind, ind+1, dp);
            int notSellToday = solve(p, k, buy, ind+1, dp);
            currProfit = max(sellToday, notSellToday);
        }
        else{
            //if curr Price is lesser, then the only option is to keep the stock.
            int notSellToday = solve(p, k, ind, ind+1, dp);
            currProfit = notSellToday;
        }
        return dp[buy][k] = currProfit;
    }
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        int ans = solve(p, k, 0, 0, dp);
        return ans;
    }
};