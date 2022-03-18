class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        unordered_map<char,bool> vis;
        unordered_map<char,int> lastIndex;
        stack<char> st;
        for(int i = 0; i<n; i++){
            vis[s[i]] = false;
            lastIndex[s[i]] = i;
        }
        
        for(int i = 0; i<n; i++){
            if(vis[s[i]]==true){
                continue;
            }
            while(!st.empty() and (s[i]<st.top() and lastIndex[st.top()]>i)){
                vis[st.top()] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]]=true;
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};