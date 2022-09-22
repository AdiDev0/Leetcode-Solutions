class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        string ans = "";
        int cnt = 0;
        int i = 0;
        while(i<n){
            int j = i;
            while(j<n and j<i+k){
                j++;
            }
            string str = s.substr(i, j-i);
            if(cnt%2==0){
                reverse(str.begin(), str.end());
            }
            cnt++;
            ans += str;
            i = j;
        }
        return ans;
    }
};