class Solution {
public:
    int kadanes(vector<int> &v ,int k){
        int n = v.size();
        set<int> s;
        s.insert(0);
        int currSum = 0;
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            currSum+=v[i];
            auto target = s.lower_bound(currSum-k);
            if(target!=s.end()){
                ans = max(ans , currSum - *target);
            }
            s.insert(currSum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        
        int maxSum = INT_MIN;
        for(int i = 0; i<m; i++){
            vector<int> v(n,0);
            for(int j = i; j<m; j++){
                for(int l = 0; l<n; l++){
                    v[l] += arr[l][j];
                }
                int currSum = kadanes(v,k);
                if(currSum<=k){
                    maxSum = max(maxSum , currSum);
                }
            }
        }
        return maxSum;
    }
};