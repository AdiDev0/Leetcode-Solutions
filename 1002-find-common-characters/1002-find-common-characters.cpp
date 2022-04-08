class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> v(n, vector<int>(26,0));
        
        for(int i = 0; i<n; i++){
            for(auto it: words[i]){
                v[i][it-'a']++;
            }
        }
        vector<string> ans;
        for(char c = 'a'; c<='z'; c++){
            int mini = INT_MAX;
            for(int i = 0; i<n; i++){
                mini = min(mini, v[i][c-'a']);
            }
            while(mini--){
                string str = "";
                str.push_back(c);
                ans.push_back(str);
            }
        }
        return ans;
    }
};