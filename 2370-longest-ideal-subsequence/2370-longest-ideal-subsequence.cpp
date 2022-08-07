class Solution {
public:
    int solve(string &s, int k, vector<vector<int>> &dp, int ind, int prevChar){
        if(ind>=s.size()){
            return 0;
        }
        if(prevChar!=-1 and dp[ind][prevChar]!=-1) return dp[ind][prevChar];
        int pick = 0;
        int notPick = 0;
        if(prevChar==-1){
            pick = 1 + solve(s, k, dp, ind+1, s[ind]-'a');
            notPick = solve(s,k,dp,ind+1,-1);
            return max(pick, notPick);
        }
        if(abs(s[ind]-'a'-prevChar) <= k){
            pick = 1 + solve(s, k, dp, ind+1, s[ind]-'a');
        }
        notPick = solve(s, k, dp, ind+1, prevChar);
        return dp[ind][prevChar] = max(pick, notPick);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (26,-1));
        int a = solve(s,k,dp,0,-1);
        return a;
    }
};