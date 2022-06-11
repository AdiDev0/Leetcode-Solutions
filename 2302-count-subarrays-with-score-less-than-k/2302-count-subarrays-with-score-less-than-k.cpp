class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long K) {
        int n = nums.size();
        int i = 0; 
        int j = 0;
        long long ans = 0;
        long long currSum = 0;
        int cnt = 0;
        while(j<n){
            currSum+=nums[j];
            cnt++;
            while((long long)currSum*cnt>=K){
                currSum-=nums[i];
                cnt--;
                i++;
            }
            ans += cnt;
            j++;
        }
        return ans;
    }
};

// for those who are confused why are we adding (i - j + 1) i.e cnt
// it adds all the subarrays that ends at j starting at i both inclusive that are valid.
// eg [1,2,3,4,5,6,7,8,9,10]
// let i = 0, i = j;
// total subarrays ending at j starting at i is 10

// [1,2,3,4,5,6,7,8,9,10]
// [2,3,4,5,6,7,8,9,10]
// [3,4,5,6,7,8,9,10]
// [4,5,6,7,8,9,10]
// [5,6,7,8,9,10]
// [6,7,8,9,10]
// [7,8,9,10]
// [8,9,10]
// [9,10]
// [10]
