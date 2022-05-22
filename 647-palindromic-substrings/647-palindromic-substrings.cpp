class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int count = 0;
        for(int i = 0; i<n; i++){
            dp[i][i] = true;
            count++;
        }
        
        // for substring of size == 2
        for(int i = 0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                count++;
            }
        }
        // for substring of size greater than 2
        for(int k = 3; k<=n; k++){
            for(int i = 0; i+k<=n; i++){
                int j = k+i-1;
                if(s[i] == s[j] and dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};