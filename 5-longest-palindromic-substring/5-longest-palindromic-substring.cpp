class Solution {
public:
    string check(string &s, int i, int j){
        int n = s.size();
        int cnt = 0;
        if(i==j){
            cnt = 1;
            i--;
            j++;
        }
        while(i>=0 and j<n and s[i]==s[j]){
            cnt+=2;
            i--;
            j++;
        }
        return s.substr(i+1, cnt);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        ans+=s[0];
        for(int i = 1; i<n; i++){
            //for odd
            string odd = check(s, i,i);
            if(odd.size()>ans.size()){
                ans = odd;
            }
            //for even
            string even = check(s,i-1,i);
            if(even.size()>ans.size()){
                ans = even;
            }
        }
        return ans;
    }
};