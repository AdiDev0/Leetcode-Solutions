class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto it: nums){
            m[it]++;
            if(m[it]==n/2) return it;
        }
        return -1;
    }
};