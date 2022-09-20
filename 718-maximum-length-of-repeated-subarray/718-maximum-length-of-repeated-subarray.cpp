class Solution {
public:
    int ans = 0;
    int solve(vector<int> &a, vector<int> &b, int i, int j, vector<vector<int>> &dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int val = 0;
        if(a[i]==b[j]){
            val = 1 + solve(a,b,i-1,j-1,dp);
            ans = max(ans, val);
        }
        solve(a,b,i-1,j,dp);
        solve(a,b,i,j-1,dp);
        
        return dp[i][j] = val;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(nums1, nums2, n-1, m-1, dp);
        return ans;
    }
};