class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        for(int i = 0; i<n-m+1; i++){
            if(s1.substr(i, m)==s2){
                return i;
            }
        }
        return -1;
    }
};