class Solution {
public:
    vector<int> ans;
    void solve(string &s, int last, int k, int n){
        if(s.size()==n){
            ans.push_back(stoi(s));
            return;
        }
        for(int i = 0; i<=9; i++){
            if(abs(last-i)==k){
                s += to_string(i);
                solve(s, i, k, n);
                s.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s = "";
        for(int i = 1; i<=9; i++){
            s+=to_string(i);
            solve(s, i, k, n);
            s.pop_back();
        }
        return ans;
    }
};