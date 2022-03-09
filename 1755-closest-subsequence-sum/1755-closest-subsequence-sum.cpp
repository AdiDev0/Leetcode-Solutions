class Solution {
public:
    void findSubsetSums(vector<int> &arr, vector<int> &ans, int index, int currSum){
        int n = arr.size();
        if(index == n){
            ans.push_back(currSum);
            return;
        }
        currSum+=arr[index];
        findSubsetSums(arr, ans, index+1, currSum);
        currSum-=arr[index];
        findSubsetSums(arr, ans, index+1, currSum);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> l,r;
        for(int i = 0; i<n; i++){
            if(i<n/2) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }
        vector<int> lSum;
        vector<int> rSum;
        findSubsetSums(l,lSum,0,0);
        findSubsetSums(r,rSum,0,0);
        
        sort(lSum.begin(), lSum.end());
        sort(rSum.begin(), rSum.end());
        
        int ans = INT_MAX;
        for(int i = 0; i<lSum.size(); i++){
            int findVal = goal-lSum[i];
            auto it = lower_bound(rSum.begin(), rSum.end(), findVal) - rSum.begin();
            if(it==rSum.size()){
                ans = min(ans, abs(goal - (lSum[i]+rSum[it-1])));
            }
            else if(it<rSum.size() and it>0){
                ans = min({ans, abs(goal - (lSum[i]+rSum[it])), abs(goal-(lSum[i]+rSum[it-1]))});
            }
            else{
                ans = min(ans, abs(goal - (lSum[i]+rSum[it])));
            }
        }
        return ans;
    }
};