//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<long long> v;
    void precompute(){
        // long long cnt = 0;
        // for(long long i = 1; i<=1e18; i++){
        //     if(__builtin_popcount(i)==3){
        //         v.push_back(i);
        //     }
        // }
        for(int i=0;i<63;i++){
            for(int j=i+1;j<63;j++){
                for(int k=j+1;k<63;k++){
                    v.push_back(pow(2,i)+pow(2,j)+pow(2,k));
                }
            }
        }
        
        sort(v.begin(),v.end());
    }
    
    long long solve(long long l, long long r){
        int a = lower_bound(v.begin(), v.end(), l) - v.begin();
        int b = lower_bound(v.begin(), v.end(), r) - v.begin();
        if(v[b]!=r) b--;
        return b-a+1;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends