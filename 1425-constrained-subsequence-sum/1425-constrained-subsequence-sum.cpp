class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n+1, 0);
        priority_queue<pair<int,int>> pq;
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            while(!pq.empty() and pq.top().second<i-k){
                pq.pop();
            }
            if(pq.empty()){
                dp[i] = nums[i];
                pq.push({dp[i], i});
            }
            else{
                dp[i] = max({nums[i]+pq.top().first, nums[i]});
                pq.push({dp[i], i});
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};