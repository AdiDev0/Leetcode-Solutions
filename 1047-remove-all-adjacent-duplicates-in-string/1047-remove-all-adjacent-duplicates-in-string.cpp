class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i<n){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]==st.top()){
                    st.pop();
                    i++;
                    continue;
                }
                else{
                    st.push(s[i]);
                }
            }
            i++;
        }
        string str = "";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        
        return str;
    }
};