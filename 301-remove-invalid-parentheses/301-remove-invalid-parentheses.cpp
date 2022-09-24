class Solution {
public:
    vector<string> ans;
    unordered_set<string> sett;
    bool isValid(string &str){
        int n = str.size();
        stack<char> s;
        for(int i = 0; i<n; i++){
            if(str[i]=='('){
                s.push('(');
            }
            else if(str[i]==')'){
                if(s.empty()) return false;
                s.pop();
            }
        }
        
        return s.size()==0;
    }
    pair<int,int> countInvalid(string &str){
        int n = str.size();
        stack<char> s;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(str[i]=='('){
                s.push('(');
            }
            else if(str[i]==')'){
                if(s.empty()){
                    cnt++;
                    continue;
                }
                s.pop();
            }
        }
        return {s.size(), cnt};
    }
    bool onlyAlpha(string &str){
        int n = str.size();
        int cnt = 0;
        for(auto it: str){
            if(it>='a' and it<='z'){
                cnt++;
            }
        }
        return cnt==n;
    }
    void solve(string &s, int open, int close, int i, string &str){
        if(i==s.size()){
            if(open!=0 or close!=0) return;
            // cout<<str<<endl;
            if(isValid(str) or str=="" or onlyAlpha(str)){
                sett.insert(str);
            }
            return;
        }
        if(open<0 or close<0) return;
        if(s[i]=='('){
            solve(s, open-1, close, i+1, str);
            str.push_back(s[i]);
            solve(s, open, close, i+1, str);
            str.pop_back();
        }
        else if(s[i]==')'){
            solve(s, open, close-1, i+1, str);
            str.push_back(s[i]);
            solve(s, open, close, i+1, str);
            str.pop_back();
        }
        else{
            str.push_back(s[i]);
            solve(s, open, close, i+1, str);
            str.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        auto temp = countInvalid(s);
        int open = temp.first;
        int close = temp.second;
        
        string str = "";
        solve(s, open, close, 0, str);
        for(auto it: sett){
            ans.push_back(it);
        }
        return ans;
    }
};