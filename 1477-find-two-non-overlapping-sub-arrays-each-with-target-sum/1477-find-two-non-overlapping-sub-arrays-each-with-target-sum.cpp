class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> m;
        vector<long> dp(n,INT_MAX);
        m[0] = -1;
        int runningSum = 0;
        for(int i = 0; i<n; i++){
            runningSum+=arr[i];
            if(m.find(runningSum-target)!=m.end()){
                dp[i] = i-m[runningSum-target];
            }
            m[runningSum] = i;
        }
        long ans = INT_MAX;
        for(int i = 0; i<n; i++){
            long prev = i-dp[i];
            if(prev>=0 and dp[i]!=INT_MAX){
                ans = min(ans, dp[prev] + dp[i]);
            }
            if(i>0){
                dp[i] = min(dp[i-1], dp[i]);
            }
        }
        return ans>n?-1:ans;
    }
};