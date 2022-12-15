//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        int sum = 0;
        int n = N;
        while(n>0){
            sum += n%10;
            n = n/10;
        }
        int cnt = 0;
        if(N>26){
            cnt = N/26;
            N = N%26;
        }
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        
        int s = 0;
        int e = 0;
        if(N%2==0){
            s = N/2;
            e = N/2;
        }
        else{
            if(sum%2==0){
                s = (N+1)/2;
                e = (N-1)/2;
            }
            else{
                s = (N-1)/2;
                e = (N+1)/2;
            }
        }
        string ans = "";
        ans += alphabets.substr(0, s);
        string temp = alphabets.substr(26-e, e);
        ans+=temp;
        for(int i = 0; i<cnt; i++){
            ans = alphabets+ans;
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
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends