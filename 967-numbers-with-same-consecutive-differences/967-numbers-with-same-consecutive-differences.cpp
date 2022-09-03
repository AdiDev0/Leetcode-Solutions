class Solution {
public:
    vector<int> ans;
    void solve(string &s, int last, int k, int n){
        if(s.size()==n){
            ans.push_back(stoi(s));
            return;
        }
        for(int i = 0; i<=9; i++){
            if(s.size()==0 and i!=0){
                s+=to_string(i);
                solve(s, i, k, n);
                s.pop_back();
            }
            else if(last!=-1 and abs(last-i)==k){
                s += to_string(i);
                solve(s, i, k, n);
                s.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s = "";
        solve(s, -1, k, n);
        return ans;
    }
};