class Solution {
public:
    bool dfs(unordered_map<string,vector<pair<double,string>>> m, unordered_map<string , int> &vis, string node, double &val,string finalNode){
        if(node == finalNode){
            return true;
        }
        for(auto it:m[node]){
            if(!vis[it.second]){
                val = val*it.first;
                vis[it.second]++;
                if(dfs(m,vis,it.second,val,finalNode)){
                    return true;
                }
                vis.erase(it.second);
                val = val/it.first;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<double,string>>> m;
        for(int i = 0; i<n; i++){
            m[equations[i][0]].push_back({values[i] , equations[i][1]});
            m[equations[i][1]].push_back({1.00000/values[i] , equations[i][0]});
        }
        
        vector<double> ans;
        unordered_map<string , int> vis;
        for(int i = 0; i<queries.size();i++){
            string a = "";
            string b = "";
            for(auto it:queries[i]){
                if(a == ""){
                    a = it;
                }
                else{
                    b = it;
                }
            }
            if(m[a].size() and m[b].size()){
                double val = 1.00000;
                if(dfs(m , vis , a,val,b)){
                    ans.push_back(val);
                }
                else{
                    ans.push_back(-1.00000);
                }
            }
            else{
                ans.push_back(-1.00000);
            }
            vis.clear();
        }
        return ans;
        
    }
};