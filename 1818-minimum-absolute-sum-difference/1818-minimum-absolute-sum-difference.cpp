class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum = 0;
        int mod = 1e9+7;
        vector<int> temp = nums1;
        for(int i = 0; i<n; i++) sum = (sum + abs(nums2[i]-nums1[i]))%mod;
        sort(temp.begin(), temp.end());
        
        int ans = INT_MAX;
        
        for(int i = 0; i<n; i++){
            auto ind = lower_bound(temp.begin(), temp.end(), nums2[i]) - temp.begin();
            // cout<<nums2[i]<<" "<<temp[ind]<<endl;
            if(ind<n)
                ans = min(ans, (sum - abs(nums2[i]-nums1[i]) + abs(nums2[i]-temp[ind]))%mod);
            if(ind>0){
                ans = min(ans, (sum - abs(nums2[i]-nums1[i]) + abs(nums2[i]-temp[ind-1]))%mod);
            }
        }
        if(ans%mod<0){
            return ans+mod;
        }
        return ans%mod;
    }
};