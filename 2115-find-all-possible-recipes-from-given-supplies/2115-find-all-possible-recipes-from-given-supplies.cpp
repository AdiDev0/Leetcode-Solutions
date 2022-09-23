class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& sup) {
        int n = r.size();
        unordered_map<string,int> ind;
        unordered_map<string, vector<string>> adj;
        
        for(int i = 0; i<n; i++){
            for(auto it: ing[i]){
                adj[it].push_back(r[i]);
                ind[r[i]]++;
            }
        }
        
        queue<string> q;
        for(auto it: sup){
            q.push(it);
        }
        
        while(!q.empty()){
            string food = q.front();
            q.pop();
            
            for(auto it: adj[food]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        vector<string> ans;
        for(auto it: ind){
            if(it.second==0){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};