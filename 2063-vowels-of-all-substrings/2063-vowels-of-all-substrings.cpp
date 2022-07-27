class Solution {
public:
    long long countVowels(string s) {
        int n = s.size();
        long long ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                ans += (long long)(i+1)*(n-i);
            }
        }
        return ans;
    }
};