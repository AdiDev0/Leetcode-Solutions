class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]>b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& r, int vf, int mp, int md) {
        int n = r.size();
        vector<vector<int>> v;
        for(auto it: r){
            if(vf==1){
                if(it[2]==1 and mp>=it[3] and md>=it[4]){
                    v.push_back(it);
                }
            }
            else{
                if(mp>=it[3] and md>=it[4]){
                    v.push_back(it);
                }
            }
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<int> ans;
        for(auto it: v){
            ans.push_back(it[0]);
        }
        return ans;
    }
};