class Solution {
public:
    int countPairs(vector<int>& del) {
        int n = del.size();
        vector<long long> v;
        for(int i = 0; i<=22; i++){
            v.push_back(pow(2,i));
        }
        unordered_map<int,int> m;
        int ans = 0;
        int mod = 1e9+7;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<v.size(); j++){
                if(m.find(v[j]-del[i])!=m.end()){
                    // cout<<v[j]-del[i]<<" "<<del[i]<<" "<<v[j]<<endl;
                    ans = (ans+m[v[j]-del[i]])%mod;
                }
            }
            m[del[i]]++;
        }
        return ans%mod;
    }
};