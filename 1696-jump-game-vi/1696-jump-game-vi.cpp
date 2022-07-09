class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        
        q.push_back(n-1);
        for(int i = n-2 ; i>=0 ; i--){
            if(q.front() - i > k){
                q.pop_front();
            }
            dp[i] = nums[i] + dp[q.front()];
            while(q.size() and dp[q.back()] < dp[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[0];
    }
};

  // priority queue solution
// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         if(n==1) return nums[0];
//         priority_queue<pair<int,int>> pq;
//         pq.push({nums[0], 0});
//         for(int i = 1; i<n; i++){
//             while(!pq.empty() and pq.top().second<max(i-k,0)){
//                 pq.pop();
//             }
//             if(i==n-1){
//                 return pq.top().first+nums[n-1];
//             }
//             pq.push({nums[i]+pq.top().first, i});
            
//         }
//         return -1;
//     }
// };


              // Giving TLE


// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n , 0);
//         dp[n-1] = nums[n-1];
//         for(int i = n-2 ; i>=0 ; i--){
//             int maxReach = i+k;
//             int j = i+1;
//             int maximum = INT_MIN;
//             while(j<= min(maxReach , n-1)){
//                 maximum = max(maximum , dp[j]);
//                 if(dp[j]>0){
//                     break;
//                 }
//                 j++;
//             }
//             dp[i] = nums[i] + maximum;
//         }
//         return dp[0];
//     }
// };
