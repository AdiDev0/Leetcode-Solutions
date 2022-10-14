class Solution {
public:
    int maxSum(vector<int>& arr1, vector<int>& arr2) {
        long long i = 0, j = 0, n = arr1.size() , m= arr2.size() , mod = 1e9+7;
        long long res = 0, sum1 = 0, sum2 = 0;
        
        
        while(i < n && j < m){
            if(arr1[i] < arr2[j]) sum1 += arr1[i++];
            else if(arr1[i] > arr2[j]) sum2 += arr2[j++];
            else{
                res += max(sum1,sum2);
                sum1 = 0,sum2 = 0;
                while(i < n && j < m && arr1[i] == arr2[j])
                {
                    res += arr1[i];
                    i++;
                    j++;
                }
            }
        }
        while(i < n) sum1 += arr1[i++];
        while(j < m) sum2 += arr2[j++];
        res += max(sum1,sum2);
        return (res + mod) % mod;
    }
};