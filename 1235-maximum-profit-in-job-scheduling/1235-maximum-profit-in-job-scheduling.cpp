class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        vector<vector<int>> v(n , vector<int>(3));
        for(int i = 0; i<n; i++){
            v[i][0] = et[i];
            v[i][1] = st[i];
            v[i][2] = profit[i];
        }
        sort(v.begin(),v.end());
        int dp[n];
        dp[0] = v[0][2];
        int ans = 0;
        ans = max(ans,dp[0]);
        for(int i = 1; i<n; i++){
            int prevProfit = v[i][2];
            int additionalProfitIndex = -1;
            int low = 0;
            int high = i-1;
            while(high>=low){
                int mid = (low+high)/2;
                if(v[mid][0] <= v[i][1]){
                    additionalProfitIndex = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            int additionalProfit = 0;
            if(additionalProfitIndex!=-1){
                additionalProfit = dp[additionalProfitIndex];
            }
            int totalProfit = prevProfit + additionalProfit;
            dp[i] = max(dp[i-1], totalProfit);
        }
        return dp[n-1];
    }
};