class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int> ms, mt;
        
        for(auto it: t){
            mt[it]++;
        }
        int ans = INT_MAX;
        int start = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        while(j<n){
            if(mt.find(s[j])!=mt.end()){
                ms[s[j]]++;
                if(ms[s[j]]<=mt[s[j]]){
                    count++;
                }
            }
            if(count>=t.size()){
                while(mt.find(s[i])==mt.end() or ms[s[i]]>mt[s[i]]){
                    ms[s[i]]--;
                    i++;
                }
                if(ans > j-i+1){
                    ans = j-i+1;
                    start = i;
                }
            }
            j++;
        }
        if(ans==INT_MAX) return "";
        return s.substr(start, ans);
    }
};