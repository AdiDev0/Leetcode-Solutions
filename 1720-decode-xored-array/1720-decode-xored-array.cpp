class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        int n = e.size();
        vector<int> ans;
        ans.push_back(first);
        for(int i = 0; i<n; i++){
            ans.push_back(e[i]^first);
            first = e[i]^first;
        }
        return ans;
    }
};

// 1  2  3

// 1^x = 1;
// x^y = 2;
// y^z = 3;
// [1, x, y, z];