class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if(sum<p){
            return -1;
        }
        if(sum%p==0){
            return 0;
        }
        
        int sumToRemove = sum%p;
        unordered_map<int,int> m;
        m[0] = -1;
        int ans = INT_MAX;
        long long int currSum = 0;
        for(int i = 0; i<n; i++){
            currSum += nums[i];
            if(m.find((currSum - sumToRemove)%p)!=m.end()){
                ans = min(ans, i-m[(currSum - sumToRemove)%p]);
            }
            m[currSum%p] = i;
        }
        
        return ans>=n?-1:ans;
    }
};