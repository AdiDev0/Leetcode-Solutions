class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        
        stack<char> st;
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i]=='['){
                st.push('[');
            }
            else if(s[i]==']' and !st.empty()){
                st.pop();
            }
        }
        
        ans = st.size();
        if(ans%2!=0) return (ans+1)/2;
        return ans/2;
    }
};