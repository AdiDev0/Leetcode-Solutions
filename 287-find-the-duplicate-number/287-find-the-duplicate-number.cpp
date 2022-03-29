class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto it: nums){
            m[it]++;
            if(m[it]>1){
                return it;
            }
        }
        return -1;
    }
};