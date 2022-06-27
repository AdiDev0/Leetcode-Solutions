class Solution {
public:
    int ans = 0;
    void solve(vector<int> &nums, int n, int t, int ind, int currSum){
        if(ind==n){
            if(currSum==t) ans++;
            return;
        }
        solve(nums, n, t, ind+1, currSum+nums[ind]);
        solve(nums, n, t, ind+1, currSum-nums[ind]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        solve(nums, n, target, 0, 0);
        return ans;
    }
};