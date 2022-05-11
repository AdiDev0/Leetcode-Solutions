class Solution {
public:
    int ans = 0;
    void solve(int n, string &s, string &temp, int index){
        if(temp.size()==n){
            // cout<<temp<<endl;
            ans++;
            return;
        }
        int i = index;
        while(i<s.size()){
            temp.push_back(s[i]);
            solve(n,s,temp,i);
            temp.pop_back();
            i++;
        }
    }
    int countVowelStrings(int n) {
        string s = "aeiou";
        string temp = "";
        solve(n,s,temp,0);
        return ans;
    }
};