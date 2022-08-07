class Solution {
public:
    int mod = 1e9+7;
    int solve(char ch, int n, unordered_map<char,string> &m, vector<vector<int>> &dp){
        if(n==0) return 1;
        if(dp[ch-'a'][n]!=-1) return dp[ch-'a'][n];
        int count = 0;
        for(auto it: m[ch]){
            count = (count + solve(it, n-1, m, dp))%mod;
        }
        return dp[ch-'a'][n] = count;
    }
    int countVowelPermutation(int n) {
        unordered_map<char,string> m;
        m['a'] = "e";
        m['e'] = "ai";
        m['i'] = "aeou";
        m['o'] = "iu";
        m['u'] = "a";
        
        string s = "aeiou";
        int ans = 0;
        vector<vector<int>> dp(26, vector<int>(n+1, -1));
        for(int i = 0; i<5; i++){
            ans = (ans + solve(s[i], n-1, m, dp))%mod;
        }
        return ans;
    }
};