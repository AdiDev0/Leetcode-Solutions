class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> v(1000002, 0);
        for(auto it: nums){
            v[it[0]]++;
            v[it[1]+1]--;
        }
        for(int i = 1; i<1000002; i++){
            v[i]+=v[i-1];
        }
        int ans = 0;
        for(int i = 0; i<1000002; i++){
            ans = max(ans, v[i]);
        }
        return ans;
    }
};

// 0 1 2 3 4 5 6 7 8 9 10
//   1         -1
//             1     -1
//     1   -1
//           1  
//   1
// 0 2 3 3 2 3 3 3 3 2     