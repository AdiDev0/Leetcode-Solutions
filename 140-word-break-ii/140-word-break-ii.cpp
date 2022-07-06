class Solution {
public:
    vector<string> ans;
    void dfs(unordered_map<int, vector<string>> &mpp, int node, string str, int n){
        if(node>=n){
            ans.push_back(str);
            return;
        }
        for(auto it: mpp[node]){
            str.push_back(' ');
            dfs(mpp, node+it.size(), str+it, n);
            str.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> m;
        vector<vector<int>> dp(n);
        
        unordered_map<int, vector<string>> mpp;
        
        for(auto it: wordDict){
            m[it]++;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i; j++){
                string str = s.substr(j, i-j+1);
                if(m.find(str)!=m.end() and j-1<0){
                    mpp[0].push_back(str);
                }
                else if(m.find(str)!=m.end()){
                    mpp[j].push_back(str);
                }
            }
        }
        // for(auto it: mpp){
        //     cout<<it.first<<" ";
        //     for(auto itr: it.second){
        //         cout<<itr<<" ";
        //     }
        //     cout<<endl;
        // }
        string str = "";
        for(auto it: mpp[0]){
            dfs(mpp, it.size(), it, n);
        }
        return ans;
    }
};