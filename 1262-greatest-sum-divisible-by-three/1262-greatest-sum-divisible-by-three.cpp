class Solution {
public:
    int solve(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp){
        if(ind>=nums.size()) return sum==0?0:-100000;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        int pick = nums[ind] + solve(nums, ind+1, (sum+nums[ind])%3, dp);
        int notPick = solve(nums, ind+1, sum, dp);
        
        return dp[ind][sum] = max(pick, notPick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return solve(nums, 0, 0, dp);
    }
};