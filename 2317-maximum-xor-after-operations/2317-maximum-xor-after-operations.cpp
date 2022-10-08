class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(32, 0);
        for(auto it: nums){
            int j = 0;
            while(it>0){
                if(it&1) v[j]++;
                it = it>>1;
                j++;
            }
        }
        int ans = 0;
        for(int i = 0; i<32; i++){
            if(v[i]>0) ans += pow(2,i);
        }
        return ans;
    }
};