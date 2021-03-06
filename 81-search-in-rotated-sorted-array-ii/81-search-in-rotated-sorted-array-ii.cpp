class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid]<nums[high]){
                if(target>nums[mid] and target <=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
                continue;
            }
            if(nums[mid] > nums[high]){
                if(target>=nums[low] and target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
                continue;
            }
            if(nums[mid] == nums[high]){
                high--;
            }
        }
        return false;
    }
};