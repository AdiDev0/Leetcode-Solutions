class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> m;
        vector<int> dp(n, 0);
        for(auto it: wordDict){
            m[it]++;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i; j++){
                string str = s.substr(j, i-j+1);
                if(m.find(str)!=m.end() and j-1<0){
                    dp[i] = 1;
                }
                else if(m.find(str)!=m.end() and dp[j-1]==1){
                    dp[i] = 1;
                }
            }
        }
        return dp[n-1]==1;
    }
};