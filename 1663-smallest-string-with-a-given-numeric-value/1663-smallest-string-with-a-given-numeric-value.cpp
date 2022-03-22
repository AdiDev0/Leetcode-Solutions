class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i = 0; i<n; i++){
            for(char ch = 'a'; ch<='z'; ch++){
                int remainingK = k-(ch-'a'+1);
                if(remainingK<=26*(n-i-1)){
                    ans.push_back(ch);
                    k-=(ch-'a'+1);
                    break;
                }
            }
        }
        return ans;
    }
};