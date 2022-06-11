class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long K) {
        int n = nums.size();
        int i = 0; 
        int j = 0;
        long long ans = 0;
        long long currSum = 0;
        int cnt = 0;
        while(j<n){
            currSum+=nums[j];
            cnt++;
            while((long long)currSum*cnt>=K){
                currSum-=nums[i];
                cnt--;
                i++;
            }
            ans += cnt;
            j++;
        }
        return ans;
    }
};
