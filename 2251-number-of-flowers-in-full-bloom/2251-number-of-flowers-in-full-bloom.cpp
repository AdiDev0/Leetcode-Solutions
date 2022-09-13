class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        int n = f.size();
        map<int,int> m, mpp;
        
        for(auto it: f){
            m[it[0]]+=1;
            m[it[1]+1]-=1;
        }
        
        int prev = 0;
        for(auto &it: m){
            it.second += prev;
            prev = it.second;
        }
        
        for(auto &it: m){
            mpp[-1*it.first] = it.second;
        }
        
        vector<int> ans;
        for(int i = 0; i<p.size(); i++){
            if(mpp.find(p[i])==mpp.end()){
                auto it = mpp.lower_bound(-1*p[i]);
                ans.push_back(it->second);
            }
            else{
                ans.push_back(mpp[p[i]]);
            }
        }
        
        return ans;
    }
};