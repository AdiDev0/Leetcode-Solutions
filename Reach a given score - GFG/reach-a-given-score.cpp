// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function


long long int count(long long int n){
    vector<int> dp(n+1, 0);
    int i = 0;
    dp[0] = 1;
    for(i = 3; i <= n; i++)
        dp[i] += dp[i - 3];
     
    for (i = 5; i <= n; i++)
        dp[i] += dp[i - 5];
     
    for (i = 10; i <= n; i++)
        dp[i] += dp[i - 10];
    return dp[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends