//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int>arr;
        
        arr.push_back(H[0]);

        int len = 1;

        int ans = 0;

        for(int i = 1;i<N;i++){

            if(H[i]>arr.back()){

                arr.push_back(H[i]);

                len++;

            }

            else{

                int ind = lower_bound(arr.begin(),arr.end(),H[i])-arr.begin();

                arr[ind]=H[i];

                ans++;

            }

        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends