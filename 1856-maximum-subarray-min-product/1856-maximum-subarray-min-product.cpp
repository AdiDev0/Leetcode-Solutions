class Solution {
public:
    vector<int> solveNse(vector<int> &nums){
        int n = nums.size();
        vector<int> nse(n, n);
        stack<int> s;
        
        for(int i = 0; i<n; i++){
            while(!s.empty() and nums[i]<nums[s.top()]){
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return nse;
    }
    vector<int> solvePse(vector<int> &nums){
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> s;
        
        for(int i = n-1; i>=0; i--){
            while(!s.empty() and nums[i]<nums[s.top()]){
                pse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return pse;
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = solveNse(nums);
        vector<int> pse = solvePse(nums);
        
        vector<long long> preSum(n, 0);
        preSum[0] = nums[0];
        
        for(int i = 1; i<n; i++){
            preSum[i] += nums[i]+preSum[i-1];
        }
        
        long long ans = 0;
        int mod = 1e9+7;
        for(int i = 0; i<n; i++){
            int nextInd = nse[i]-1;
            int prevInd = pse[i]+1;
            long long sum = 0;
            if(prevInd-1>=0){
                sum = preSum[nextInd] - preSum[prevInd-1];
            }
            else{
                sum = preSum[nextInd];
            }
            ans = max(ans, (long long)nums[i]*sum);
        }
        return ans%mod;
    }
};