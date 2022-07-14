
class Solution {
public:
    unordered_map<long,long> ans;
    int solve(unordered_map<int, vector<int>> &m, int root, int nodes){
        if(m[root].size()==0){
            ans[nodes-1]++;
            return 1;
        }
        
        vector<int> v = m[root];
        int l = 0;
        int r = 0;
        if(v.size()==2){
            l = solve(m, v[0], nodes);
            r = solve(m, v[1], nodes);
            int val = (nodes-l-r-1);
            long currAns = (long)l*r*(val!=0?val:1);
            ans[currAns]++;
        }
        else{
            l = solve(m, v[0], nodes);
            int val = (nodes-l-1);
            long currAns = (long)l*(val!=0?val:1);
            ans[currAns]++;
        }
        return l+r+1;
    }
    int countHighestScoreNodes(vector<int>& par) {
        int n = par.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<n; i++){
            m[par[i]].push_back(i);
        }
        int nodes = n;
        solve(m, 0, nodes);
        long node = -1;
        long freq = 0;
        for(auto it: ans){
            if(it.first>node){
                node = it.first;
                freq = it.second;
            }
        }
        return freq;
    }
};

