class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int,int> m;
        set<int> st;
        for(int i = 0; i<n; i++){
            m[mat[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> a,b;
        
        for(int i = 0; i<n; i++){
            if(!m[mat[i][0]] and st.find(mat[i][0])==st.end()){
                a.push_back(mat[i][0]);
                st.insert(mat[i][0]);
            }
        }
        for(auto it: m){
            if(it.second==1){
                b.push_back(it.first);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(), b.end());
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};