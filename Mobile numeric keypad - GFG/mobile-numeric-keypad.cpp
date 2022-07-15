// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

#define ll long long
	public:
	int ans = 0;
	ll solve(vector<vector<int>> &v,int N, int row, int col, vector<vector<vector<ll>>> &dp){
	    if(N==0){
	        return 1;
	    }
	    if(dp[row][col][N]!=-1) return dp[row][col][N];
	    
	    int x[5] = {0,-1,0,1,0};
	    int y[5] = {0,0,1,0,-1};
	    ll count = 0;
	    for(int i = 0; i<5; i++){
	        int nextR = row+x[i];
	        int nextC = col+y[i];
	        if(nextR<4 and nextR>=0 and nextC<3 and nextC>=0 and v[nextR][nextC]!=-1){
	            count += solve(v, N-1, nextR, nextC, dp);
	        }
	    }
	    return dp[row][col][N] = count;
	}
	
	long long getCount(int N){
	    vector<vector<int>> v;
	    v.push_back({1,2,3});
	    v.push_back({4,5,6});
	    v.push_back({7,8,9});
	    v.push_back({-1,0,-1});
	    vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(4, vector<ll>(N+1, -1)));
	    ll tot = 0;
	    for(int i = 0; i<4; i++){
	        for(int j = 0; j<3; j++){
	            if(v[i][j]==-1) continue;
	            tot += solve(v, N-1, i, j, dp);
	
	        }
	    }
	    return tot;
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends