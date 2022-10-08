class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int dist = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        for(int i = 0; i<n;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            left = i+1;
            right = n-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum>target){
                    if(abs(sum-target)<dist){
                        dist = abs(sum-target);
                        ans = sum;
                    }
                    right--;
                }
                else if(sum<target){
                    if(abs(target-sum)<dist){
                        dist = abs(target-sum);
                        ans = sum;
                    }
                    left++;
                }
                else if(sum==target){
                    return target;
                }
            }
        }
        return ans;
    }
};