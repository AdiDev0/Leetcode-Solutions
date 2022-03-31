class Solution {
public:
    bool splitArray(vector<int> &nums, int maxParts, int maxSum){
        int n = nums.size();
        int currSum = 0;
        int parts = 1;
        
        for(int i = 0; i<n; i++){
            currSum+=nums[i];
            if(currSum>maxSum){
                currSum = nums[i];
                parts++;
            }
            if(parts>maxParts){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, nums[i]);
            sum+=nums[i];
        }
        int low = maxi;
        int high = sum;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(splitArray(nums, m, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};