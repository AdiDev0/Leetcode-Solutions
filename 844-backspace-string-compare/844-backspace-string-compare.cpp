class Solution {
public:
    void solve(string &s , stack<char> &st){
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(st.empty() and s[i]=='#'){
                continue;
            }
            if(s[i]=='#'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        stack<char> st;
        solve(s,st);
        string a = "";
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
        solve(t,st);
        string b = "";
        while(!st.empty()){
            b.push_back(st.top());
            st.pop();
        }
        return a==b?true:false;
    }
};