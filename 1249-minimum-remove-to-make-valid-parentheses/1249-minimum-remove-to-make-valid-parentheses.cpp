class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int open = 0;
        for(int i = 0; i<n; i++){
            if(s[i]>='a' and s[i]<='z'){
                st.push(s[i]);
            }
            else if(s[i]=='('){
                st.push('(');
                open++;
            }
            else if(s[i]==')'){
                if(open>0){
                    open--;
                    st.push(')');
                }
            }
        }
        string str = "";
        while(!st.empty()){
            char temp = st.top();
            if(open>0 and temp == '('){
                open--;
            }
            else{
                str.push_back(temp);
            }
            st.pop();
        }
        reverse(str.begin(), str.end());
        // int lastClose = 0;
        // for(int i = 0; i<str.size(); i++){
        //     if(str[i]==')'){
        //         lastClose = i;
        //     }
        // }
        // if(open>0){
        //     string ans = "";
        //     // reverse(str.begin(), str.end());
        //     for(int i = lastClose+1; i<str.size(); i++){
        //         if(str[i]=='(' and open>0){
        //             open--;
        //         }
        //         else{
        //             ans.push_back(str[i]);
        //         }
        //     }
        //     return ans;
        // }
        return str;
    }
};