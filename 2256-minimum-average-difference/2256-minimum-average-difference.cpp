class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        int ans = INT_MAX;
        int ind = -1;
        long long s = 0;
        for(int i = 0; i<n-1; i++){
            s+=nums[i];
            long long l = s/(i+1);
            long long r = (sum-s)/(n-i-1);
            // cout<<l<<" "<<r<<endl;
            if(ans>abs(l-r)){
                ans = abs(l-r);
                ind = i;
            }
        }
        if(sum/n<ans){
            return n-1;
        }
        return ind;
    }
};