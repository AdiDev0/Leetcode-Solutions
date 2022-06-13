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
            if(count-maxi>k){
                if(m[s[i]]>1) m[s[i]]--;
                else m.erase(s[i]);
                count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
// Since we are looking for the longest sub-string, we don't need to shrink the sliding window by more than 1 character:
// by shrinking the left pointer more than 1, it means that we are shrinking the sliding window. We don't want to shrink it because we don't care. If we have a max window length 5, if we shrink the sliding window to 4, even if there are valid substring of this sliding window length, we don't care because we only care for window length greater or equal to 5 (to be returned as final answer)
