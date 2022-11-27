// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1)return 0;
//         vector<unordered_map<long,long>> dp(n);
//         int ans = 0;
//         for(int i = 1; i<n; i++){
//             for(int j = 0; j<i; j++){
//                 int cd = (long)nums[i]-nums[j];
//                 if(cd>INT_MAX or cd<INT_MIN){
//                     continue;
//                 }
//                 if(dp[j][cd]!=0){
//                     dp[i][cd]+=dp[j][cd]+1;
//                     ans+=dp[j][cd];
//                 }
//                 else{
//                     dp[i][cd] = 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution 
{
    public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int res = 0;
        vector<unordered_map<long long int, int>> diff(nums.size());
        for (int i = 0; i < nums.size(); i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                long long int d = (long long int)nums[i] - nums[j];
                if (!diff[j].count(d)) 
                {
                    diff[i][d]++;
                } else 
                {
                    res += diff[j][d];
                    diff[i][d] += diff[j][d] + 1;
                }
            }
        }
        return res;
    }
};