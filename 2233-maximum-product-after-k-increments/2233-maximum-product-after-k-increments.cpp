class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        long mult = 1;
        long mod = 1e9+7;
        while(k--){
            int a = pq.top();
            pq.pop();
            pq.push(a+1);
        }
        while(!pq.empty()){
            mult = (long long)(mult*pq.top())%mod;
            pq.pop();
        }
        return mult;
    }
};