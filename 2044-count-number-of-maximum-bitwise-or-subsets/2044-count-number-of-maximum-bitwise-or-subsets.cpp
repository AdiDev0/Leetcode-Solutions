class Solution {
public:
    int maxi = -1;
    int freq = 0;
    int n = 0;
    void solve(vector<int> &nums, int i, int curr){
        if(i==n){
            if(curr>maxi){
                maxi = curr;
                freq = 1;
            }
            else if(curr==maxi){
                freq++;
            }
            return;
        }
        solve(nums, i+1, curr|nums[i]);
        solve(nums, i+1, curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        solve(nums, 0, 0);
        return freq;
    }
};