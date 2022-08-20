class Solution {
public:
    int solve(vector<int> &p, int k, bool buy, int ind, vector<vector<vector<int>>> &dp){
        if(ind==p.size()){
            return 0;
        }
        if(k<=0) return 0;
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        
        if(buy){
            int ifBuyToday = solve(p, k, false, ind+1, dp) - p[ind];
            int ifNotBuyToday = solve(p, k, true, ind+1, dp);
            return dp[ind][buy][k] = max(ifBuyToday, ifNotBuyToday);
        }
        else{
            int ifSellToday = solve(p, k-1, true, ind+1, dp) + p[ind];
            int ifNotSelltoday = solve(p, k, false, ind+1, dp);
            return dp[ind][buy][k] = max(ifSellToday, ifNotSelltoday);
        }
        return 0;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(n==0) return 0;
        int k = 2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(p, k, true, 0, dp);
    }
};