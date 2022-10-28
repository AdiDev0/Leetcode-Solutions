class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string> > ans;
        if(strs.size() == 0){
            return ans;
        }
        unordered_map<string ,vector<string>> m;
        int n = strs.size();
        
        for(int i = 0; i<n ; i++){
            string s = strs[i];
            sort(s.begin() , s.end());
            m[s].push_back(strs[i]);
            
        }
        
        for(auto it:m){
           ans.push_back(it.second);
        }
        
        return ans;
    }
};