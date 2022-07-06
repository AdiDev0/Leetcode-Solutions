// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        int n = a.size();
        sort(a.begin(), a.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            while(i<n and a[j]-a[i]>k){
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return n-ans;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends