class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> pse(n,-1), nse(n,n);
        stack<int> s;
        
        //previous smaller element
        for(int i = n-1; i>=0; i--){
            if(s.empty()){
                s.push(i);
            }
            while(!s.empty() and nums[s.top()]>nums[i]){
                pse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        
        //next smaller element
        for(int i = 0; i<n; i++){
            if(s.empty()){
                s.push(i);
            }
            while(!s.empty() and nums[i]<nums[s.top()]){
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int prev = pse[i]+1;
            int next = nse[i]-1;
            
            if(prev>k or next<k){
                continue;
            }
            ans = max(ans, nums[i]*(next-prev+1));
        }
        return ans;
    }
};