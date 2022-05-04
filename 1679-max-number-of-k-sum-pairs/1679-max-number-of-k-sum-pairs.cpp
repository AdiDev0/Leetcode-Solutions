class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(m.find(k-nums[i])!=m.end()){
                ans++;
                if(m[k-nums[i]]==1) m.erase(k-nums[i]);
                else m[k-nums[i]]--;
            }
            else{
                m[nums[i]]++;
            }
        }
        return ans;
    }
};