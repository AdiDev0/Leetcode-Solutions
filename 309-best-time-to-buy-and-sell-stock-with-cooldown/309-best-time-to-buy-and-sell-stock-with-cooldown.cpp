class Solution {
public:
    int solve(vector<int>& p, int ind, bool cooldown, bool buy, vector<vector<vector<int>>> &dp){
        if(ind==p.size()) return 0;
        
        if(dp[ind][buy][cooldown]!=-1) return dp[ind][buy][cooldown];
        
        if(cooldown){
            return dp[ind][buy][cooldown] = solve(p, ind+1, false, true, dp);
        }
        else{
            if(buy){
                // i can buy today
                int ifBuyToday = solve(p, ind+1, false, false, dp) - p[ind];
                int ifNotBuyToday = solve(p, ind+1, false, true, dp);
                return dp[ind][buy][cooldown] = max(ifBuyToday, ifNotBuyToday);
            }
            else{
                //i can sell today
                int ifSellToday = solve(p, ind+1, true, true, dp) + p[ind];
                int ifNotSellToday = solve(p, ind+1, false, false, dp);
                return dp[ind][buy][cooldown] = max(ifSellToday, ifNotSellToday);
            }
        }
        return 0;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(p, 0, false, true, dp);
    }
};