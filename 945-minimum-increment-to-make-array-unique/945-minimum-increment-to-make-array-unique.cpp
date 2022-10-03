class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(10000001, -1);
        int ans = 0;
        map<int,int> m;
        for(auto it: nums){
            if(v[it]==1) m[it]++;
            else v[it] = 1;
        }
        int ind = 0;
        for(auto it: m){
            int freq = it.second;
            int val = it.first;
            while(freq--){
                while(v[ind]!=-1 or ind<val){
                    ind++;
                }
                v[ind] = val;
                ans += ind-val;
            }
        }
        return ans;
    }
};