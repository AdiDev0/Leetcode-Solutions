class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> ans;
        ans.push_back(env[0][1]);
        
        for(int i = 1; i<n; i++){
            int val = ans.back();
            if(env[i][1]>val){
                ans.push_back(env[i][1]);
            }
            else{
                int ind = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[ind] = env[i][1];
            }
        }
        return ans.size();
    }
};