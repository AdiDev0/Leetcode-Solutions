class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums) sum+=it;
        if(sum<x) return -1;
        if(sum==x) return n;
        sum-=x;
        int maxi = 0;
        int i = 0;
        int j = 0;
        int currSum = 0;
        while(j<n){
            currSum+=nums[j];
            while(currSum>sum){
                currSum-=nums[i++];
            }
            if(currSum==sum) maxi = max(maxi, j-i+1);
            j++;
        }
        while(i<n and currSum>=sum){
           if(currSum==sum) maxi = max(maxi, j-i);
         i++;
        }
        if(maxi==0) return -1;
        return n-maxi;
    }
};