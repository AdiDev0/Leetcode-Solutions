class Solution {
public:
    int solve(vector<int> &nums, int ind, int n, vector<int> &mult, int k, int m, vector<vector<int>> &dp){
        if(k>=m) return 0;
        if(dp[ind][k]!=INT_MIN) return dp[ind][k];
        
        int takel = solve(nums, ind+1, n, mult, k+1, m, dp) + mult[k]*nums[ind];
        int taker = solve(nums, ind, n, mult, k+1, m, dp) + mult[k]*nums[(n-1)-(k-ind)];
        
        return dp[ind][k] = max(takel, taker);
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int k = 0;
        int m = mult.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MIN));
        return solve(nums, l, n, mult, k, m, dp);
    }
};