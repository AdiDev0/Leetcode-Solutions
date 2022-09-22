class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string ans = "";
        while(i<n){
            int j = i;
            while(j<n and s[j]!=' '){
                j++;
            }
            string temp = s.substr(i, j-i);
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += ' ';
            i = j+1;
        }
        ans.pop_back();
        return ans;
    }
};