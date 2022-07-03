class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 1; i<n; i++){
            v.push_back(nums[i]-nums[i-1]);
        }
        vector<int> dp(n-1, 0);
        for(int i = 0; i<n-1; i++){
            if(v[i]!=0){
                dp[i] = 1;
            }
        }
        int maxPos = 0;
        int maxNeg = 0;
        for(int i = 0; i<n-1; i++){
            if(v[i]>0){
                dp[i] = maxNeg+1;
                maxPos = max(maxPos, dp[i]);
            }
            else if(v[i]<0){
                dp[i] = maxPos+1;
                maxNeg = max(maxNeg, dp[i]);
            }
        }
        int ans = 0;
        for(auto it: dp){
            ans = max(ans, it);
        }
        return ans+1;
    }
};





// class Solution {
// public:
//     int solve(vector<int> &pos, vector<int> &neg){
//         int n = pos.size();
//         int m = neg.size();
//         int ans = 0;
//         for(int i = 0; i<m; i++){
//             int val = lower_bound(pos.begin(), pos.end(), neg[i]) - pos.begin();
//             if(i==m-1){
//                 if(val==n) ans+=1;
//                 else ans+=2;
//             }
//             else{
//                 if(val<neg[i+1]){
//                     ans+=2;
//                 }
//             }
//         }
//         cout<<ans<<endl;
//         return ans+1;
//     }
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> v;
//         for(int i = 1; i<n; i++){
//             v.push_back(nums[i]-nums[i-1]);
//         }
//         vector<int> pos, neg;
//         for(int i = 0; i<v.size(); i++){
//             cout<<v[i]<<" ";
//             if(v[i]>0) pos.push_back(i);
//             if(v[i]<0) neg.push_back(i);
//         }
//         cout<<endl;
//         for(auto it: pos){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//         for(auto it: neg){
//             cout<<it<<" ";
//         }
//         // solve(pos, neg);
//         return max(solve(pos, neg), solve(neg,pos));
//         // return 1;
//     }
// };