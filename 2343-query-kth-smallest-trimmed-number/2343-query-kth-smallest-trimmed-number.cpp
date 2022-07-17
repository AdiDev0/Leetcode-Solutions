class Solution {
public:
    
    int solve(vector<string> &nums, int dig, int k, vector<vector<int>> &dp){
        int n = nums.size();
        priority_queue< pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>> > pq;
        int m = nums[0].size();
        for(int i = 0; i<n; i++){
            string s = nums[i].substr(m-dig, dig);
            pq.push({s, i});
        }
        int cnt = 1;
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            dp[dig][cnt] = ind;
            cnt++;
        }
        return dp[dig][k];
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> ans; 
        vector<vector<int>> dp(101, vector<int>(101, -1));
        for(int i = 0; i<q.size(); i++){
            int k = q[i][0];
            int dig = q[i][1];
            if(dp[dig][k]!=-1){
                ans.push_back(dp[dig][k]);
            }
            else{
                int a = solve(nums, dig, k, dp);
                ans.push_back(a);
            }
        }
        return ans;
    }
};