class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            m[s[j]]++;
            while(m.size()!=j-i+1){
                if(m[s[i]]>1){
                    m[s[i]]--;
                }
                else{
                    m.erase(s[i]);
                }
                i++;
            }
            if(m.size()==j-i+1){
                ans = max(ans, j-i+1);
            }
            j++;
        }
        return ans;
    }
};