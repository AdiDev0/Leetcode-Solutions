class Solution {
public:
    bool solve(vector<int> &stones, int ind, int unit, unordered_map<long, long> &m, vector<vector<int>> &dp){
        if(ind==stones.size()-1){
            return true;
        }
        if(ind>stones.size()) return false;
        if(dp[ind][unit]!=-1) return dp[ind][unit];
        
        bool ans = false;
        if(unit>1 and m[stones[ind]+unit-1]){
            ans = ans or solve(stones, m[stones[ind]+unit-1], unit-1, m, dp);
        }
        if(m[stones[ind]+unit]){
            ans = ans or solve(stones, m[stones[ind]+unit], unit, m, dp);
        }
        if(m[stones[ind]+unit+1]){
            ans = ans or solve(stones, m[stones[ind]+unit+1], unit+1, m, dp);
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
    }
};