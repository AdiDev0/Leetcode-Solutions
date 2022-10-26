class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 1e18;
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end());
        vector<long long> pre, suf;
        long long costSum = 0, nc = 0;  // nc = nums*cost
        for(int i = 0; i<n; i++){
            pre.push_back((long long)v[i].first*costSum - nc);
            costSum += (long long)v[i].second;
            nc += (long long)v[i].first*v[i].second;
        }
        costSum = 0;
        nc = 0;
        for(int i = n-1; i>=0; i--){
            ans = min(ans, pre[i] + abs((long long)v[i].first*costSum - nc));
            costSum += (long long)v[i].second;
            nc += (long long)v[i].first*v[i].second;
        }
        return ans;
    }
};
