class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxBit = (1<<maximumBit)-1;  // all one bit of size maximumBit ..if maximumBit==3 the val is 111
        vector<int> ans;
        int Xor = 0;
        for(auto it: nums){
            Xor ^= it;
            int oppXor = Xor^maxBit;
            ans.push_back(oppXor);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 2^20 = 1048576