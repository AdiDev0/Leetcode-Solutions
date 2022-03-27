class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int deletions = 0;
        
        for(int i = 0; i<n-1; i++){
            if((i-deletions)%2==0){
                if(nums[i]==nums[i+1]){
                    deletions++;
                }
            }
        }
        if((n-deletions)%2!=0){
            deletions++;
        }
        return deletions;
    }
};