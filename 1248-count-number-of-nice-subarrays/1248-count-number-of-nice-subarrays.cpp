class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int oddCount = 0;
        m[0] = 1;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]%2!=0) oddCount++;
            if(m.find(oddCount-k)!=m.end()){
                ans+=m[oddCount-k];
            }
            m[oddCount]++;
        }
        return ans;
    }
};