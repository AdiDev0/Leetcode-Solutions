class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
    // vector<vector<int>> ans;
    // void findPermutations(vector<int> &nums, int index){
    //     if(index == nums.size()){
    //         ans.push_back(nums);
    //         return;
    //     }
    //     int i = index;
    //     while(i<nums.size()){
    //         if(i!=index and nums[i] == nums[index]){
    //             i++;
    //             continue;
    //         }
    //         swap(nums[i] , nums[index]);
    //         findPermutations(nums,index+1);
    //         // swap(nums[i] , nums[index]);
    //         i++;
    //     }
    //     return;
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     if(nums.size() <=1){
    //         ans.push_back(nums);
    //         return ans;
    //     }
    //     sort(nums.begin() , nums.end());
    //     findPermutations(nums , 0);
    //     return ans;
    // }
};