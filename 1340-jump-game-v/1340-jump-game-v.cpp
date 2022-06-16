class Solution {
public:
    int solve(vector<int> &arr,int n, int d, vector<int> &dp, int ind){
        if(dp[ind]!=-1) return dp[ind];
        int i = ind-1, j = ind+1;
        int l = max(ind-d,0);
        int r = min(n-1,ind+d);
        int maxi = 0;
        while(i>=l and arr[i]<arr[ind]){
            maxi = max(maxi, solve(arr,n,d,dp,i)+1);
            i--;
        }
        while(j<=r and arr[j]<arr[ind]){
            maxi = max(maxi, solve(arr,n,d,dp,j)+1);
            j++;
        }
        return dp[ind] = maxi;
    }
    int maxJumps(vector<int>& arr, int d){
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int currAns = solve(arr,n, d, dp,i);
            ans = max(ans, currAns);
        }
        return ans+1;
    }
};