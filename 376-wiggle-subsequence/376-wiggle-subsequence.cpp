class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 1; i<n; i++){
            v.push_back(nums[i]-nums[i-1]);
        }
        vector<int> dp(n-1, 0);
        for(int i = 0; i<n-1; i++){
            if(v[i]!=0){
                dp[i] = 1;
            }
        }
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<i; j++){
                if(v[i]<0 and v[j]>0 and dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
                else if(v[i]>0 and v[j]<0 and dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        int ans = 0;
        for(auto it: dp){
            // cout<<it<<" ";
            ans = max(ans, it);
        }
        return ans+1;
    }
};