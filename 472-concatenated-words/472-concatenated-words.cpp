class Solution {
public:
    bool solve(string s, unordered_map<string, int> &m) {
        int n = s.size();
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i; j++){
                string str = s.substr(j, i-j+1);
                if(m.find(str)!=m.end() and j-1<0){
                    dp[i] = 1;
                }
                else if(m.find(str)!=m.end() and dp[j-1]>=1){
                    dp[i] += dp[j-1];
                }
            }
        }
        return dp[n-1]>1;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, int> m;
        for(auto it: words){
            m[it]++;
        }
        vector<string> ans;
        for(auto it: words){
            if(solve(it, m)) ans.push_back(it);
        }
        return ans;
    }
};