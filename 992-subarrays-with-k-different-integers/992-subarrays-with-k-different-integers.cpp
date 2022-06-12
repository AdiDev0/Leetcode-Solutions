class Solution {
public:
    // subarray with at most k diff int.
    int solve(vector<int> &nums, int k){
        int n = nums.size();
        unordered_map<int,int> m;
        int i = 0, j = 0, ans = 0;
        while(j<n){
            m[nums[j]]++;
            while(m.size()>k){
                if(m[nums[i]]>1) m[nums[i]]--;
                else m.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};