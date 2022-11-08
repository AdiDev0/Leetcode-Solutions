class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i = 0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(isupper(s[i]) and islower(st.top()) and tolower(s[i])==st.top() ){
                    st.pop();
                }
                else if(islower(s[i]) and isupper(st.top()) and s[i]==tolower(st.top()) ){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};