class Solution {
public:
    int kadanes(vector<int> &v ,int k){
        int n = v.size();
        unordered_map<int,int> s;
        s[0]++;
        int currSum = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            currSum+=v[i];
            if(s.find(currSum-k)!=s.end()){
                ans+=s[currSum-k];
            }
            s[currSum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        
        int ans = 0;
        for(int i = 0; i<m; i++){
            vector<int> v(n,0);
            for(int j = i; j<m; j++){
                for(int l = 0; l<n; l++){
                    v[l] += arr[l][j];
                }
                ans += kadanes(v,k);
            }
        }
        return ans;
    }
};