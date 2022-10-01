class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = (s[0]=='0') ? 0: 1;
        for(int i=2; i<=n; i++)
        {
            int one = s[i-1] - '0';
            int two = 10*(s[i-2]-'0') + (s[i-1]-'0');
            if(one>=1)
                dp[i]+= dp[i-1];
            if(two>=10 && two<=26)
                dp[i]+= dp[i-2];
        }
        return dp[n];
    }
};