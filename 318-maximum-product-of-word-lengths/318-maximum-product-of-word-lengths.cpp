class Solution {
public:
    bool match(vector<int> &a, vector<int> &b){
        for(int i = 0; i<26; i++){
            if(a[i]>0 and b[i]>0){
                return true;
            }
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freq;
        map<vector<int>, int> m;
        
        for(int i = 0; i<n; i++){
            string s = words[i];
            vector<int> v(26,0);
            for(int j = 0; j<s.size(); j++){
                v[s[j]-'a']++;
            }
            freq.push_back(v);
        }    
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(!match(freq[i], freq[j])){
                    int a = words[i].size();
                    int b = words[j].size();
                    ans = max(ans, a*b);
                }
            }
        }
        return ans;
    }
};