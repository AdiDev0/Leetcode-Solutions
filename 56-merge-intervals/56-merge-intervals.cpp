class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i<n){
            int a = intervals[i][0];
            int b = intervals[i][1];
            int j = i+1;
            while(j<n and intervals[j][0]<=b){
                a = min(a, intervals[j][0]);
                b = max(b, intervals[j][1]);
                j++;
            }
            ans.push_back({a,b});
            i = j;
        }
        return ans;
    }
};