class Solution {
public:
    int solve(vector<int>& p, int ind, bool buy, vector<vector<int>> &dp, int fee){
        if(ind==p.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy){
           // i can buy today
            int ifBuyToday = solve(p, ind+1, false, dp, fee) - p[ind];
            int ifNotBuyToday = solve(p, ind+1, true, dp, fee);   
            return dp[ind][buy] = max(ifBuyToday, ifNotBuyToday);
        }
        else{
            //i can sell today
            int ifSellToday = solve(p, ind+1, true, dp, fee) + p[ind]-fee;
            int ifNotSellToday = solve(p, ind+1, false, dp, fee);
            return dp[ind][buy] = max(ifSellToday, ifNotSellToday);
        }
        return 0;
    }
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(p, 0, true, dp, fee);
    }
};