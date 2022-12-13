//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int maxSum = 0;
    int solve(int arr[], int maxi, int n, int k){
        int sum = 0;
        int cnt = 1;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            if(sum>maxi){
                maxSum = max(maxSum, sum-arr[i]);
                sum = arr[i];
                cnt++;
            }
        }
        maxSum = max(maxSum, sum);
        return cnt;
    }
    int splitArray(int arr[] ,int n, int k) {
        int low = 0;
        int high = 0;
        for(int i = 0; i<n; i++){
            low = max(low, arr[i]);
            high += arr[i];
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int val = solve(arr, mid, n, k);
            // cout<<mid<<endl;
            if(val<=k){
                ans = maxSum;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            maxSum = 0;
        }
        return ans;
    }
};
// 8  9   10     14     21    34


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends