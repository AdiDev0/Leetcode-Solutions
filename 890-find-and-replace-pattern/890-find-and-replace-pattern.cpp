class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pa) {
        int n = words.size();
        vector<string> ans;
        unordered_map<char,vector<int>> m1, m2;
        for(int i = 0; i<pa.size(); i++){
            m1[pa[i]].push_back(i);
        }
        
        for(auto it: words){
            string s = it;
            unordered_map<char,vector<int>> m2;
            for(int i = 0; i<s.size(); i++){
                m2[s[i]].push_back(i);
            }
            bool f = true;
            int j = 0;
            if(s.size()!=pa.size()) continue;
            while(j<s.size()){
                if(m1[pa[j]]!=m2[s[j]]){
                    f = false;
                    break;
                }
                j++;
            }
            if(f) ans.push_back(s);
            m2.clear();
        }
        return ans;
    }
};