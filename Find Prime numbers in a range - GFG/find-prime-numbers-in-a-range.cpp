// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
       vector<bool> seive(N+1,true);
       
       for(int i = 2; i*i<=N; i++){
           if(seive[i]==true){
               for(int j = i*i; j<=N; j+=i){
                   seive[j] = false;
               }
           }
       }
       vector<int> primes;
       for(int i = max(M,2); i<=N; i++){
           if(seive[i]) primes.push_back(i);
       }
       return primes;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends