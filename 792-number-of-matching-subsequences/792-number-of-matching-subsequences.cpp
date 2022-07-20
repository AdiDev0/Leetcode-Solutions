class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words){
        int n = s.size();
        unordered_map<char,vector<int>> mpp;
        
        for(int i = 0; i<n; i++){
            mpp[s[i]].push_back(i);
        }
        int ans = 0;
        for(auto it: words){
            int prevInd = -1;
            string str = it;
            bool flag = false;
            for(int i = 0; i<str.size(); i++){
                if(mpp.find(str[i])==mpp.end()) break;
                auto index = upper_bound(mpp[str[i]].begin(), mpp[str[i]].end(), prevInd);
                if(index == mpp[str[i]].end()) break;
                prevInd = *index;
                if(i==str.size()-1){
                    flag = true;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};