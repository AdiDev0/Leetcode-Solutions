// class Solution {
// public:
//     static bool compare(string a, string b){
//         if(a.size()==b.size()){
//             return a>b;
//         }
//         return a.size()>b.size();
//     }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int k = strs.size();
        
//         for(int i = 0; i<k; i++){
//             sort(strs[i].begin(), strs[i].end(), greater());
//         }
//         sort(strs.begin(), strs.end(), compare);
//         for(int i = 0; i<k; i++){
//             cout<<strs[i]<<" ";
//         }
//         cout<<endl;
//         vector<vector<int>> dp(k,vector<int>(3,0));
//         int ans = 0;
//         for(int i = 0; i<k; i++){
//             int ones = 0;
//             int zeros = 0;
//             for(auto &it: strs[i]){
//                 if(it=='1') ones++;
//                 else zeros++;
//             }
//             dp[i][0] = 1;
//             dp[i][1] = ones;
//             dp[i][2] = zeros;
//         }
//         for(int i = 0; i<k; i++){
//             int ones = 0;
//             int zeros = 0;
//             for(int j = 0; j<i; j++){
//                 if(dp[j][0]+1>dp[i][0] and dp[j][2]+dp[i][2]<=m and dp[j][1]+dp[i][1]<=n){
//                     dp[i][0] = dp[j][0]+1;
//                     ones = dp[j][1];
//                     zeros = dp[j][2];
//                     // ans = max(ans , dp[i][0]);
//                 }
//                 else if(dp[j][0]+1==dp[i][0] and dp[j][2]+dp[i][2]<=m and dp[j][1]+dp[i][1]<=n){
//                     // dp[i][0] = dp[j][0]+1;
//                     ones = min(ones,dp[j][1]);
//                     zeros = min(zeros,dp[j][2]);
//                     // ans = max(ans , dp[i][0]);
//                 }
//             }
//             dp[i][1] += ones;
//             dp[i][2] += zeros;
//             cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
//         }
//         for(int i = 0; i<k; i++){
//             if(dp[i][0]>ans and dp[i][1]<=n and dp[i][2]<=m){
//                 ans = dp[i][0];
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int dp[101][101][601]; // m,n,idx
    int helper(vector<string>& strs, int m, int n, int idx)
    {
        /* Helper takes, strs arr, m (max 0s), n (max 1s) and idx (current string).
        *  For each strs[idx] we either consider it or not.
        *  When we consider the str[idx] string, we'll also update m and n.
        *  At the end, we'll return max(considered, not_considered).
        */
        
        if (idx >= strs.size()) { // Reached end of strs arr.
            return 0;
        }
        // If result is already calculated
        // then return it, no need to go further.
        if (dp[m][n][idx] != -1) 
            return dp[m][n][idx];

        // res1 holds the max number of elems if strs[idx]
        // is NOT considered for final set.
        int res1 = helper(strs, m, n, idx+1);
        
        // res2 holds the max number of elems if strs[idx]
        // is considered for final set.
        // (Don't forget to update m and n.)
        int count[2] = {0,0};
        for (int i = 0; i < strs[idx].length(); i++){
            if (strs[idx][i] == '0') count[0]++;
            else count[1]++;
        }
        int res2 = 0;
        if (!(m - count[0] < 0 || n - count[1] < 0)){
            res2 = 1 + helper(strs, m - count[0] , n - count[1], idx+1);
        }
        
        // Store result for current m, n and idx in dp
        // and return it.
        dp[m][n][idx] = max(res2, res1);
        return dp[m][n][idx];
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(strs, m, n, 0);
    }
};