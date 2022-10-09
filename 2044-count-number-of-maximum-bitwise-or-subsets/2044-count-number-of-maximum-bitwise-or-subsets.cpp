class Solution {
public:
    int maxi = -1;
    int freq = 0;
    int n = 0;
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int i, int curr, vector<int> &v){
        if(i==n){
            if(curr>maxi){
                maxi = curr;
                freq = 1;
                ans.clear();
                ans.push_back(v);
            }
            else if(curr==maxi){
                freq++;
                ans.push_back(v);
            }
            return;
        }
        v.push_back(nums[i]);
        solve(nums, i+1, curr|nums[i], v);
        v.pop_back();
        solve(nums, i+1, curr, v);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        solve(nums, 0, 0, v);
        // cout<<maxi<<endl;
        // for(auto it: ans){
        //     for(auto i: it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return freq;
    }
};