class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<wall[i].size(); j++){
                if(j!=0){
                    wall[i][j] += wall[i][j-1];
                }
                if(j!=wall[i].size()-1){
                    m[wall[i][j]]++;
                }
            }
        }
        
        int ans = n;
        for(auto it: m){
            ans = min(ans, n-it.second);
        }
        return ans;
    }
};