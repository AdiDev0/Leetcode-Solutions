// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(arr[0]==0 and n>1) return -1;
        if(n==1) return 0;
        if(arr[0]>=n-1) return 1;
        int jumps = 1;
        int steps = arr[0];
        int maxReach = arr[0];
        int maxInd = 0;
        
        for(int i = 1; i<n; i++){
            if(maxReach < arr[i]+i){
                maxReach = arr[i]+i;
                maxInd = i;
            }
            if(maxReach>=n-1) return jumps+1;
            if(maxReach<=i) break;
            steps--;
            if(steps==0){
                jumps++;
                int stepsCanTake = maxReach-maxInd;
                int stepsAlreadyTaken = i-maxInd;
                steps = stepsCanTake - stepsAlreadyTaken;
            }
        }
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends