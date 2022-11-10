class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int c) {
        int n = nums.size();
        priority_queue<int> pq1, pq2;
        
        int i = 0;
        while(i<min(c,n)){
            pq1.push(-1*nums[i]);
            i++;
        }
        i--;
        int j = n-1;
        while(j>i and j>=(n-c)){
            pq2.push(-1*nums[j]);
            j--;
        }
        j++;
        long long ans = 0;
        while(k--){
            int a = INT_MAX, b = INT_MAX;
            if(!pq1.empty()){
                a = -1*pq1.top();
            }
            if(!pq2.empty()){
                b = -1*pq2.top();
            }
            
            if(a<=b){
                ans += a;
                pq1.pop();
                if(i+1<j and i+1<n){
                    i++;
                    pq1.push(-1*nums[i]);
                }
            }
            else{
                ans += b;
                pq2.pop();
                if(j-1>0 and j-1>i){
                    j--;
                    pq2.push(-1*nums[j]);
                }
            }
        }
        return ans;
    }
};