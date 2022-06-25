class Solution {
public:
    int dp[10001][7][7];
    int mod = 1e9+7;
    int solve(int n, int last, int seclast, int ind){
        if(ind == n){
            return 1;
        }
        if(dp[ind][last][seclast]!=0) return dp[ind][last][seclast];
        long ans = 0;
        int i = 1;
        while(i<=6){
            if(i!=last and i!=seclast){
                if(last==0 or __gcd(i,last)==1){
                  ans = (ans + solve(n, i,last,ind+1))%mod;
                }
            }
            i++;
        }
        return dp[ind][last][seclast] = ans;
    }
    int distinctSequences(int n) {
        return solve(n, 0, 0, 0);
    }
};