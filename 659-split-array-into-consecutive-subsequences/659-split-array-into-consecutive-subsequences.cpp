class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m, lastEle;
        for(auto it: nums){
            m[it]++;
        }
        for(int i = 0; i<n; i++){
            int val = nums[i];
            if(m[val]<=0) continue;
            m[val]--;
            
            if(lastEle[val-1]>0){
                lastEle[val-1]--;
                lastEle[val]++;
            }
            else if(m[val+1]>0 and m[val+2]>0){
                lastEle[val+2]++;
                m[val+1]--;
                m[val+2]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
    