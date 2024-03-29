//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> h;
        
        for(int i = 0; i < N; i++){
            h.push(arr[i]);
        }
        
        int ans = 0;
        while(h.size() > 1){
            int sum = h.top();
            h.pop();
            sum += h.top();
            h.pop();
            h.push(sum);
            ans += sum;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends