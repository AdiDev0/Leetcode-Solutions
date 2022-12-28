//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int n = nums.size();
	    int ans = 0;
	    for(int i = 1; i<n-1; i++){
	        int j = i-1;
	        int k = i+1;
	        int cntj = 0;
	        int cntk = 0;
	        while(j>=0){
	            if(nums[j]<nums[i]){
	                cntj++;
	            }
	            j--;
	        }
	        while(k<n){
	            if(nums[k]> nums[i]){
	                cntk++;
	            }
	            k++;
	        }
	        ans += cntj*cntk;
	    }
	    return ans;
	}
	
// 	2 1 5 8 6 4 3
	
// 	2 5 8
// 	2 5 6
// 	1 5 8
// 	1 5 6
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends