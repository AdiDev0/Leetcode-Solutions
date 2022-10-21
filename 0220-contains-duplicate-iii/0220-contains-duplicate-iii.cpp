class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int val) {
        int n = nums.size();
        multiset<int> s;
        
        int j = 0;
        for(int i = 0; i<n; i++){
            if(i-j>k){
                s.erase(nums[j++]);
            }
            auto it = s.lower_bound(nums[i]-val);
            if(it!=s.end() and abs(*it - nums[i])<=val){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};