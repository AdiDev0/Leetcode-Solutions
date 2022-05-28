class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        long long tot = n*(n+1)/2;
        return tot-sum;
    }
};