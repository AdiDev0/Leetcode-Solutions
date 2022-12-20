//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int nums[], int n){ 
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        int max2 = INT_MIN;
        int min2 = INT_MAX;
        
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            max1 = max(max1, nums[i]+i);
            min1 = min(min1, nums[i]+i);
            ans = max(ans, max1 - min1);
            
            max2 = max(max2, nums[i]-i);
            min2 = min(min2, nums[i]-i);
            ans = max(ans, max2-min2);
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends