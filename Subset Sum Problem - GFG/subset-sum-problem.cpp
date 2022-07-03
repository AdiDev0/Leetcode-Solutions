// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int> &arr, int sum, int ind, vector<vector<int>> &dp){
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        if(ind==0) return arr[ind]==sum;
        if(sum==0) return dp[ind][sum] = true;
        bool pick = false;
        if(sum-arr[ind]>=0){
            pick = solve(arr, sum-arr[ind], ind-1, dp);
        }
        bool notPick = solve(arr, sum, ind-1, dp);
        
        return dp[ind][sum] = pick or notPick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(arr, sum, n-1, dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends