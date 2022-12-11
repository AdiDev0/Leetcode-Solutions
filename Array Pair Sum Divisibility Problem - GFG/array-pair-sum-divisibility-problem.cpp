//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> m;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]%k==0){
                cnt++;
                continue;
            }
            if(m.find(k-nums[i]%k)!=m.end()){
                m[k-nums[i]%k]--;
                if(m[k-nums[i]%k]==0) m.erase(k-nums[i]%k);;
            }
            else{
                m[nums[i]%k]++;
            }
        }
        return m.size()==0 and cnt%2==0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends