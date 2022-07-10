class Solution {
public:
    vector<int> nextGreaterEle(vector<int> &nums){
        int n = nums.size();
        vector<int> v(n,n);
        stack<int> s;
        for(int i = 0; i<n; i++){
            while(!s.empty() and nums[s.top()]<nums[i]){
                v[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
    vector<int> prevGreaterEle(vector<int> &nums){
        int n = nums.size();
        vector<int> v(n,-1);
        stack<int> s;
        for(int i = n-1; i>=0; i--){
            while(!s.empty() and nums[s.top()]<nums[i]){
                v[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
    int validSubarraySize(vector<int>& nums, int t) {
        int n = nums.size();
        vector<int> v(n, 0);
        for(int i = 0; i<n; i++){
            if(nums[i]>t){
                v[i] = 1;
                continue;
            }
            if(t%nums[i]==0){
                v[i] = t/nums[i] + 1;
            }
            else{
                v[i] = ceil((float)t/nums[i]);
            }
        }
        
        auto nge = nextGreaterEle(v);
        auto pge = prevGreaterEle(v);
        
        for(int i = 0; i<n; i++){
            int mini = v[i];
            int l = pge[i];
            int j = nge[i];
            
            int count = j-l-1;
            if(count>=mini){
                return count;
            }
        }
        return -1;
    }
};