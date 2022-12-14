//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        int i = 0;
        int cnt = 0;
        int ans = 0;
        for(auto it: str) cnt += it=='1';
        int zeros = 0;
        int ones = 0;
        int l = 0;
        int r = 0;
        int fl = -1;
        int fr = 0;
        while(i<n){
            if(str[i]=='1') ones++;
            else zeros++;
            
            if(ones>zeros){
                ones = 0;
                zeros = 0;
                l = i+1;
            }
            else{
                if(ans<cnt+zeros-ones){
                    ans = cnt+zeros-ones;
                    r = i;
                    fl = l;
                }
            }
            i++;
        }
        if(fl>r or fl==-1) return {-1};
        return {fl+1,r+1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends