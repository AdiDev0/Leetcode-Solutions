class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        v.push_back({1});
        if(n==1) return v;
        v.push_back({1,1});
        if(n==2) return v;
        for(int j = 3; j<=n; j++){
            vector<int> temp(j,1);
            int s = v.size()-1;
            for(int i = 1; i<j-1; i++){
                temp[i] = v[s][i-1]+v[s][i];
            }
            v.push_back(temp);
        }
        return v;
    }
};