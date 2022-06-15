class Solution {
public:
    static bool cmp(string &a, string &b){
        return a.size()<b.size();
    }
    bool match(string &a, string &b){
        int i=0,j=0,n=b.size();
        int cnt = 0;
        while(i<a.size() and j<n){
            if(a[i]==b[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return cnt==b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), cmp);
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(words[j].size()+1==words[i].size() and match(words[i],words[j]) and dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};