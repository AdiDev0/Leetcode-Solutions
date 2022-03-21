class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i = 0; i<n; i++){
            m[s[i]] = i;
        }
        int i = 0;
        int start = i;
        int end = 0;
        vector<int> ans;
        while(i<n){
            end = max(end, m[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start = i+1;
            }
            i++;
        }
        return ans;
    }
};