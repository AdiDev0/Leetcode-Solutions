class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(100003, 0);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            int d = abs(nums1[i]-nums2[i]);
            diff[d]++;
            maxi = max(maxi, d);
        }
        int k = k1+k2;
        for(int i = maxi; i>0; i--){
            diff[i-1] += min(diff[i], k);
            if(diff[i]>=k){
                diff[i] -= k;
                k = 0;
            }
            else{
                k -= diff[i];
                diff[i] = 0;
            }
            if(k==0) break;
        }
        
        long long ans = 0;
        for(int i = 0; i<=maxi; i++){
            ans += (long long)i*i*diff[i];
        }
        return ans;
    }
};