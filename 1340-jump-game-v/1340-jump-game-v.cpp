class Solution {
public:
    int solve(vector<int> &arr, int d, vector<int> &dp, int ind){
        int n = arr.size();
        if(dp[ind]!=-1) return dp[ind];
        int lmax = arr[ind];
        int rmax = arr[ind];
        int i = ind-1, j = ind+1;
        int l = max(ind-d,0);
        int r = min(n-1,ind+d);
        int maxi = 0;
        while(i>=l and arr[i]<lmax){
            maxi = max(maxi, solve(arr,d,dp,i)+1);
            i--;
        }
        while(j<=r and arr[j]<rmax){
            maxi = max(maxi, solve(arr,d,dp,j)+1);
            j++;
        }
        return dp[ind] = maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        // int a = solve(arr, d, dp,0);
        for(int i = 0; i<n; i++){
            int a = solve(arr, d, dp,i);
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return ans+1;
    }
};