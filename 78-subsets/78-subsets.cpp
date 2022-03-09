class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,int> m;
    void solve(vector<int> &nums, int index, vector<int> &v){
        int n = nums.size();
        if(index==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        solve(nums, index+1, v);
        v.pop_back();
        solve(nums, index+1, v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(nums, 0, v);
        return ans;
    }
};