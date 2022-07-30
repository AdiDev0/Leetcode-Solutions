class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        int n = a.size();
        int m = b.size();
        vector<string> ans;
        vector<int> count(26,0);
        for(int i = 0; i<m; i++){
            string s = b[i];
            vector<int> countFreq(26,0);
            for(int j = 0; j<s.size();j++){
                countFreq[s[j]-'a']+=1;
            }
            for(int j = 0; j<26; j++){
                count[j] = max(count[j] , countFreq[j]);
            }
        }
        
        for(int i = 0; i<n; i++){
            string s = a[i];
            vector<int> freq(26,0);
            for(int j = 0; j<s.size(); j++){
                freq[s[j]-'a']++;
            }
            bool flag = true;
            for(int j = 0; j<26; j++){
                if(freq[j]<count[j]){
                    flag = false;
                }
            }
            if(flag){
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};