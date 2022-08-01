class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> lr(n, INT_MIN);
        lr[0] = nums[0];
        
        for(int i = 1; i<n; i++){
            lr[i] = max(nums[i]+i, lr[i-1]);
        }
        // for(auto it: lr) cout<<it<<" ";
        cout<<endl;
        vector<int> rl(n,INT_MIN);
        rl[n-1] = nums[n-1]-(n-1);
        
        for(int i = n-2; i>=0; i--){
            rl[i] = max(nums[i]-i, rl[i+1]);
        }
        // for(auto it: rl) cout<<it<<" ";
        for(int i = 0; i<n-1; i++){
            ans = max(ans, lr[i]+rl[i+1]);
        }
        return ans;
    }
};