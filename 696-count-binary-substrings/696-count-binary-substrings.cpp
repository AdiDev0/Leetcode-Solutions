class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prevCount = 0;
        int currCount = 1;
        int ans = 0;
        for(int i = 1; i<n; i++){
            if(s[i]!=s[i-1]){
                ans+=min(currCount, prevCount);
                prevCount = currCount;
                currCount = 1;
            }
            else{
                currCount++;
            }
        }
        ans+=min(currCount, prevCount);
        return ans;
    }
};