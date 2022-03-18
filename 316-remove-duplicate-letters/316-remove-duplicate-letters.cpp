class Solution {
public:
    string removeDuplicateLetters(string s){
        int n = s.size();
        unordered_map<char,int> m, mpp;
        stack<char> st;
        for(int i = 0; i<n; i++){
            m[s[i]] = i;
        }
        string ans = "";
        for(int i = 0; i<n; i++){
            if(mpp[s[i]]) continue;
            while(!st.empty() and st.top()>s[i] and m[st.top()]>i){
                mpp.erase(st.top());
                st.pop();
            }
            mpp[s[i]]++;
            st.push(s[i]);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};