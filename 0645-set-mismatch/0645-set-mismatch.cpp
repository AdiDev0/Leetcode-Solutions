class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int rep = 0;
        int miss = 0;
        for(int i = 0; i<n; i++){
            if(nums[abs(nums[i])-1] < 0){
                rep = abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
                miss = i+1;
            }
            
        }
        return {rep, miss};
    }
};


// 0 1 2 3 4
// -3 -4 -2 -2 1