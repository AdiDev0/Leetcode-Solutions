class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            int curr = abs(nums[i]);
            if(nums[curr]<0){
                return curr;
            }
            else{
                nums[curr]*=-1;
            }
        }
        return -1;
    }
};