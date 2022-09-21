class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m = q.size();
        vector<int> ans;
        
        int sum = 0;
        for(auto it: nums) if(abs(it)%2==0) sum+=it;
        
        for(auto it: q){
            int val = it[0];
            int ind = it[1];
            
            if(nums[ind]%2!=0){
                nums[ind]+=val;
                if(nums[ind]%2==0){
                    sum+=nums[ind];
                }
            }
            else{
                sum-=nums[ind];
                nums[ind]+=val;
                if(nums[ind]%2==0){
                    sum+=nums[ind];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};