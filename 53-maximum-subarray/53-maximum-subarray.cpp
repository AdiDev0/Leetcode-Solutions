class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int csum = nums[0];
        int osum = nums[0];
        for(int i = 1; i<n; i++){
            if(csum>0){
                csum+=nums[i];
            }
            else{
                csum = nums[i];
            }
            osum = max(osum, csum);
        }
        return osum;
    }
};