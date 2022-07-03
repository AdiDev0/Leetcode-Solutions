class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 1; i<n; i++){
            v.push_back(nums[i]-nums[i-1]);
        }
        int maxPos = 0;
        int maxNeg = 0;
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            int currAns = 0;
            if(v[i]>0){
                currAns = maxNeg+1;
                maxPos = max(maxPos, currAns);
            }
            else if(v[i]<0){
                currAns = maxPos+1;
                maxNeg = max(maxNeg, currAns);
            }
            ans = max(ans, currAns);
        }
        return ans+1;
    }
};
