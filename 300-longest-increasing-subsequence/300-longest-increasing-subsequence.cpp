class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1];
        dp[0] = 1;
        for(int i = 1; i<n ; i++){
            dp[i] = 1;
            for(int j = 0; j<i; j++){
                if(arr[j] < arr[i] and dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
        }
        int ans = INT_MIN;
        return *max_element(dp,dp+n);
        
    }
};