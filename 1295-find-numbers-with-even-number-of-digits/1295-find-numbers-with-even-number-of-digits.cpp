class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto it: nums){
            int k = (int)log10(it)+1;
            k%2==0 ? ans++: ans;
        }
        return ans;
    }
};
// Given a Number N, we can find the number of digits in N as
// K = floor(log10(N) + 1)
// or
// k = (int) log10(N)+1;