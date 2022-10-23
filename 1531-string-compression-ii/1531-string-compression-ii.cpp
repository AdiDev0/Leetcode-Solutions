

class Solution {
public:
    int solve(string &s, int k, int i, char last, int cnt, vector<vector<vector<vector<int>>>> &dp){
        
        if(k<0) return 101;
        
        if(i>=s.size()){
            return 0;
        }
        
        if(cnt >= 10){
            cnt = 10;
        }
            
        if(dp[i][last-'a'][cnt][k]!=-1) return dp[i][last-'a'][cnt][k];
        
        int mini = 101;
        
        //del
        mini = min(mini, solve(s, k-1, i+1, last, cnt, dp));
        
        //not del
        if(s[i]!=last){
            //char len of 1 is added
            mini = min(mini, 1 + solve(s, k, i+1, s[i], 1, dp));
        }
        else{
            if(cnt==1 or cnt==9){
                // cnt len will increase so 1 is added
                mini = min(mini, 1 + solve(s, k, i+1, last, cnt+1, dp));
            }
            else{
                mini = min(mini, solve(s, k, i+1, last, cnt+1, dp));
            }
        }
        return dp[i][last-'a'][cnt][k] = mini;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        bool allSame = true;
            
        // Base case: check for all char are same
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i-1])
            {
                allSame = false;
                break;
            }
        }

        if(allSame){
            n  -= k;
            if(n == 1) 
                return 1;
            if(n==0){
                return 0;
            }
            int l = to_string(n).size();
            return l+1;            
        }
        vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>>(27, vector<vector<int>>(11, vector<int>(101, -1))));
        
        return solve(s, k, 0, 'z', 0, dp);
    }
};

