class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> pre(n, 0);
        pre[0] = nums[0];
        for(int i = 1; i<n; i++){
            pre[i]+=pre[i-1]+nums[i];
        }
        int ans = 1;
        int i = 0;
        int j = 0;
        while(j<n){
            long val = (long)(j-i+1)*nums[j];
            long sum = (pre[j]-(i>0?pre[i-1]:0));
            long diff = val-sum;
            if(diff>k){
                i++;
                continue;
            }
            else{
                ans = max(ans, j-i+1);
            }
            j++;
        }
        return ans;
    }
};