class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        // priority_queue<pair<int,int>> pq;
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> v;
        int i = 0;
        while(i<n){
            int count = 0;
            int j = i;
            while(j<n and nums[j]==nums[i]){
                count++;
                j++;
            }
            v.push_back({nums[i], count});
            i = j;
        }
        if(v.size()==1) return 0;
        i = v.size()-1;
        int ans = 0;
        while(i>=0){
            if(i>0){
                ans+=v[i].second;
                v[i-1].second+=v[i].second;
            }
            i--;
        }
        return ans;
    }
};