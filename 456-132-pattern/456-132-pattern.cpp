class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int secondMax = -1e9;
        for(int i = n-1; i>=0; i--){
            if(s.empty()){
                s.push(nums[i]);
            }
            if(nums[i]<secondMax) return true;
            while(!s.empty() and nums[i]>s.top()){
                secondMax = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};