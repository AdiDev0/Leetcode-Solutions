class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        // Declare variables
        double maxAverage = INT_MIN;
        // Declare and initalise the sliding window
        double curTotal = 0.0;
        for (int i = 0; i < k; i++) {
            curTotal += nums[i];
        }
        maxAverage = max(maxAverage, curTotal / k);
        // Travel the sliding window
        for (int i = k; i < nums.size(); i++) {
            curTotal -= nums[i - k];
            curTotal += nums[i];
            maxAverage = max(maxAverage, curTotal / k);
        }
        // Return final result
        return maxAverage;
    }
};