class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        m[0] = -1;
        int currSum = 0;
        for(int i = 0; i<n; i++){
            currSum+=nums[i];
            if(k!=0){
                currSum = currSum%k;
            }
            if(m.find(currSum)!=m.end()){
                if(i-m[currSum]>1){
                    return true;
                }
            }
            else{
                m[currSum] = i;
            }
        }
        return false;
    }
};