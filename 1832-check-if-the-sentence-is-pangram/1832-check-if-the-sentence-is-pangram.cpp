class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(auto it: s){
            m[it]++;
        }
        return m.size()==26;
    }
};