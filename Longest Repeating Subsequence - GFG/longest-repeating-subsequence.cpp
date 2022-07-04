// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
    int solve(string &a,int n, int m, vector<vector<int>> &dp){
        if(n<0 or m<0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        int pickN = 0, pickM = 0, pickBoth = 0;
        if(a[n]==a[m] and n!=m){
            pickBoth = 1 + solve(a,n-1,m-1, dp);
        }
        else{
            if(n-1!=m){
                pickN = solve(a,n-1,m, dp);
            }
            if(n!=m-1){
                pickM = solve(a,n,m-1, dp);
            }
        }
        return dp[n][m] = max({pickBoth, pickN, pickM});
    }
	int LongestRepeatingSubsequence(string str){
	    int n = str.size();
	    vector<vector<int>> dp(n, vector<int>(n,-1));
	    return solve(str,n-1,n-1, dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends