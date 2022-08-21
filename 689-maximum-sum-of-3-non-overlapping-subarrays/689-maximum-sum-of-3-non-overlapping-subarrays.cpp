class Solution {
public:
    pair<int, vector<int>> solve(vector<int> &v, int k, int cnt, int ind, vector<vector<pair<int,vector<int>>>> &dp){
        if(ind>=v.size()) return {0,{}};
        if(cnt<0) return {0,{}};
        if(dp[ind][cnt].first!=-1) return dp[ind][cnt];  
        
        auto pick = solve(v, k, cnt-1, ind+k,dp);
        auto notPick = solve(v, k, cnt, ind+1, dp);
        
        pick.first+=v[ind];
        
        if(pick.first>=notPick.first){
            pick.second.push_back(ind);
            dp[ind][cnt] = pick;
        }
        else{
            dp[ind][cnt] = notPick;
        }
        return dp[ind][cnt];
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v;
        int sum = 0;
        int i = 0;
        int j = 0;
        while(j<k-1){
            sum+=nums[j++];
        }
        while(j<n){
            sum+=nums[j++];
            v.push_back(sum);
            sum-=nums[i++];
        }
        vector<vector<pair<int,vector<int>>>> dp(v.size(),vector<pair<int,vector<int>>>(3,{-1,{}}));
        auto ans = solve(v, k, 2, 0, dp);
        sort(ans.second.begin(), ans.second.end());
        return ans.second;
    }
};