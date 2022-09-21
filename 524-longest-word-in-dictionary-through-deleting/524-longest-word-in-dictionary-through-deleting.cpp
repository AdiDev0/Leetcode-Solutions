class Solution {
public:
    string findLongestWord(string s, vector<string>& dic) {
        int n = s.size();
        unordered_map<char, vector<int>> m;
        
        for(int i = 0; i<n; i++){
            m[s[i]].push_back(i);
        }

        string ans = "";
        
        for(auto it: dic){
            int last = -1;
            bool found = true;
            for(int i = 0; i<it.size(); i++){
                if(m.find(it[i])!=m.end()){
                    auto ind = upper_bound(m[it[i]].begin(), m[it[i]].end(), last) - m[it[i]].begin();
                    if(ind==m[it[i]].size()){
                        found=false;
                        break;
                    }
                    else{
                        last = m[it[i]][ind];
                    }
                }
                else{
                    found = false;
                    break;
                }
            }
            if(found){
                if(ans.size()<it.size()){
                    ans = it;
                }
                else if(ans.size()==it.size()){
                    ans = min(ans, it);
                }
            }
        }
        return ans;
    }
};