// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int pre_sum=0;
        int count=0;
        unordered_map<int,int>um;
        for(int i=0;i<N;i++){
            pre_sum+=Arr[i];
             um[pre_sum]++;
             if(pre_sum==k){
                count++;
            }
            if(um.count(pre_sum-k)==1){
                count+=um[pre_sum-k];
            }
           
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends