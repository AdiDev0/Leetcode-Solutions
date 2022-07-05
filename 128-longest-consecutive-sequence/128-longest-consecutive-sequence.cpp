class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i = 0; i<n; i++){
            m[nums[i]] = -1;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            int count = 0;
            int val = nums[i];
            while(m[val]){
                if(m[val]>-1){
                    count+=m[val];
                    break;
                }
                else{
                    count++;
                    val++;
                }
            }
            m[nums[i]] = max(m[nums[i]] , count);
            ans = max(ans,count);
        }
        return ans;
    }
};