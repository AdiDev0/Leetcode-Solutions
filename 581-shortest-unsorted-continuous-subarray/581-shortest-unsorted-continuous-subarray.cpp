class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        for(int i = 1; i<n; i++){
            if(nums[i-1]>nums[i]){
                start = i-1;
                break;
            }
        }
        for(int i = n-2; i>=0; i--){
            if(nums[i+1]<nums[i]){
                end = i+1;
                break;
            }
        }
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = start; i<=end; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        
        while(start-1>=0 and nums[start-1]>mini){
            start--;
        }
        while(end+1<=n-1 and nums[end+1]<maxi){
            end++;
        }
        // cout<<start<<" "<<end<<endl;
        if(start==0 and end==0) return 0;
        return end-start+1;
    }
};