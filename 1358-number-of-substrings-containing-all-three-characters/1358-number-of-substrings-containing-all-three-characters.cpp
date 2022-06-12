class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i=0,j=0,ans=0;
        unordered_map<char, int> m;
        while(j<n){
            m[s[j]]++;
            while(m.size()==3){
                ans += n-j;
                if(m[s[i]]>1) m[s[i]]--;
                else m.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};