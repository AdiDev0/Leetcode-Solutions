class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int a = nums[0];
        if(n==1) return a;
        int b = max(a,nums[1]);
        if(n==2) return b;
        int ans = 0;
        for(int i = 2; i<n; i++){
            int currAns = max(a+nums[i],b);
            a = b;
            b = currAns;
            ans = max(ans,currAns);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1){
//             return nums[0];
//         }
//         int dp[n];
//         dp[0] = nums[0];
//         for(int i = 1;i<n;i++){
//             dp[i] = nums[i];
//             for(int j =0; j<i-1; j++){
//                 if(nums[i]+dp[j]>dp[i]){
//                     dp[i] = nums[i]+dp[j];
//                 }
//             }
//         }
//         int ans = 0;
//         for(int i =0 ;i<n; i++){
//             ans = max(ans,dp[i]);
//         }
//         return ans;
//     }
// };