class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto it:nums) sum+=it;
        long prevSum = 0;
        long ans = INT_MAX;
        for(int i = 0; i<n; i++){
            long afterSum = sum-prevSum-nums[i];
            long afterChanges = afterSum - (long)nums[i]*(n-i-1);
            long prevChanges = (long)nums[i]*i - prevSum;
            ans = min(ans, (long)afterChanges+prevChanges);
            prevSum+=nums[i];
        }
        return ans;
    }
};