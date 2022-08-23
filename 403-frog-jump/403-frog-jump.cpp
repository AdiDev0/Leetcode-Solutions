class Solution {
public:
    bool solve(vector<int> &stones, int ind, int unit, unordered_map<long, long> &m, vector<vector<int>> &dp){
        if(ind==stones.size()-1){
            return true;
        }
        if(ind>stones.size()) return false;
        if(dp[ind][unit]!=-1) return dp[ind][unit];
        
        int prevUnit = unit;
        bool ans = false;
        if(prevUnit>1 and m[stones[ind]+prevUnit-1]){
            ans = ans or solve(stones, m[stones[ind]+prevUnit-1], prevUnit-1, m, dp);
        }
        if(m[stones[ind]+prevUnit]){
            ans = ans or solve(stones, m[stones[ind]+prevUnit], prevUnit, m, dp);
        }
        if(m[stones[ind]+prevUnit+1]){
            ans = ans or solve(stones, m[stones[ind]+prevUnit+1], prevUnit+1, m, dp);
        }
        return dp[ind][unit] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<long, long> m;
        for(int i = 0; i<n; i++){
            m[stones[i]] = i;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(stones, 0, 0, m, dp);
        // return ans;
    }
};