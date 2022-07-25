class Solution {
public:
    int getLeft(vector<int> &nums, int low, int high, int t){
        int n = nums.size();
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(t==nums[mid]){
                ans = mid;
                high = mid-1;
            }
            else if(t>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    int getRight(vector<int> &nums, int low, int high, int t){
        int n = nums.size();
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(t==nums[mid]){
                ans = mid;
                low = mid+1;
            }
            else if(t<nums[mid]){
                high = mid-1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target==nums[mid]){
                int left = getLeft(nums, 0, mid, target);
                int right = getRight(nums, mid, n-1, target);
                return {left, right};
            }
            else if(target>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return {-1,-1};
    }
};