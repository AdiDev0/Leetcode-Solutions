//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m){
    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int mod = 1e9+7;
    int ans = 0;
    int tot = n*m - 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int cnt = 0;
            for(int k = 0; k<8; k++){
                int nr = i+x[k];
                int ncol = j+y[k];
                if(nr>=0 and nr<n and ncol>=0 and ncol<m){
                    cnt++;
                }
            }
            ans = (ans+tot-cnt)%mod;
        }
    }
    return ans;
}