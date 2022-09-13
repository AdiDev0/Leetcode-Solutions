class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==val){
                c++;
                nums[i]=INT_MAX;  
            }
        }
        sort(nums.begin(), nums.end()); 
        nums.erase(nums.end()-c, nums.end()); 
        return nums.size();
    }
};