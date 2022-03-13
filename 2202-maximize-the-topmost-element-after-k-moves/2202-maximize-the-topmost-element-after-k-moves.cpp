class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1){
            if(k%2==1){
                return -1;
            }
            return nums[0];
        }
        int maxi=INT_MIN,ans=nums[0];
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
        }
        if(k>nums.size()){
            return maxi;
        }
        if(k==nums.size()){
            maxi=INT_MIN;
            for(int i=0;i<nums.size()-1;i++){
                maxi=max(nums[i],maxi);
            }   
            return maxi;
        }
        else{
            maxi=INT_MIN;
            for(int i=0;i<k-1;i++){
                maxi=max(maxi,nums[i]);
            }
            ans=max(maxi,nums[k]);
        }
        return ans;
    }
};