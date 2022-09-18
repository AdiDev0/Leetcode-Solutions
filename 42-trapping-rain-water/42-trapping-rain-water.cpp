class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n<3){
            return 0;
        }
        int left[n];
        int right[n];
        left[0] = heights[0];
        right[n-1] = heights[n-1];
        for(int i = 1; i<n-1; i++){
            left[i] = max(left[i-1], heights[i]);
            right[n-1-i] = max(right[n-i],heights[n-1-i]);
        }
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            ans+=min(left[i],right[i]) - heights[i];
        }
        return ans;
    }
};