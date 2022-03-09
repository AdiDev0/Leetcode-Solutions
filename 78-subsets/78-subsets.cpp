class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,int> m;
    void solve(vector<int> &nums, int index, vector<int> &v){
        int n = nums.size();
        if(index==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        solve(nums, index+1, v);
        v.pop_back();
        solve(nums, index+1, v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(nums, 0, v);
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         map<vector<int> , int> m;
//         int n = nums.size();
//         int numOfSubset = 1<<n;
//         vector< vector<int> >ans;
//         for(int i = 0; i<numOfSubset ; i++){
//             int a = i;
//             int index = 0;
//             vector<int> subans;
//             while(a!=0){
                
//                 if(a&1==1){
//                     subans.push_back(nums[index]);
//                 }
//                 index++;
//                 a = a>>1;
//             }
//             sort(subans.begin() , subans.end());
//             if(m[subans]>0){
//                 continue;
//             }
//             else{
//                 m[subans]++;
//                 ans.push_back(subans);
//             }
            
//         }
//         return ans;
//     }
// };