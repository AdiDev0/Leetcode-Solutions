class Solution {
public:
    long long appealSum(string s) {
        long long n = s.size();
        long long ans = 0;
        vector<int> lastOcc(27, -1);
        
        for(long long i = 0; i<n; i++){
            int ind = s[i] - 'a';
            ans += (n-i)*(i-lastOcc[ind]);
            lastOcc[ind] = i;
        }
        return ans;
    }
};