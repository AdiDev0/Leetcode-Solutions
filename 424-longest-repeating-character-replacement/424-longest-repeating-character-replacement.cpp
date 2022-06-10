class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<int,int> m;
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = 0;
        int ans = 0;
        while(j<n){
            m[s[j]]++;
            count++;
            maxi = max(maxi, m[s[j]]);
            if(count-maxi<=k){
                ans = max(ans, count);
            }
            while(count-maxi>k){
                if(m[s[i]]>1) m[s[i]]--;
                else m.erase(s[i]);
                maxi = max(maxi, m[s[i]]);
                count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};