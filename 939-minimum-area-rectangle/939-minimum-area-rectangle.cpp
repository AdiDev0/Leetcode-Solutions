class Solution {
public:
    int minAreaRect(vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<int, set<int>> m;
        for(int i = 0; i<n; i++){
            m[p[i][0]].insert(p[i][1]);
        }
        
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int x1 = p[i][0];
                int y1 = p[i][1];
                
                int x2 = p[j][0];
                int y2 = p[j][1];
                if(x1!=x2 and y1!=y2){
                    if(m[x1].find(y2)!=m[x1].end() and m[x2].find(y1)!=m[x2].end()){
                        int area = abs(x2-x1)*abs(y2-y1);
                        ans = min(ans, area);
                    }
                }
                
            }
        }
        return ans==INT_MAX?0:ans;
    }
};