class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int,long> m;
        int mod = 1e9+7;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int j = 0;
            m[arr[i]]++;
            while(j<i){
                if(arr[i]%arr[j]==0){
                    int toFind = arr[i]/arr[j];
                    if(m.find(toFind)!=m.end()){
                        m[arr[i]] = (m[arr[i]] + (long long)m[arr[j]]*m[toFind])%mod;
                    }
                }
                j++;
            }
            ans = (ans + m[arr[i]])%mod;
        }
        return ans;
    }
};