class Solution {
public:
    vector<string> split(string s){
        int n = s.size();
        int i = 0;
        vector<string> v;
        while(i<n){
            string temp = "";
            int j = i+1;
            while(s[j]!='/' and j<n){
                temp.push_back(s[j]);
                j++;
            }
            if(temp!=""){
                v.push_back(temp);
            }
            i = j;
        }
        return v;
    }
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> v;
        v = split(path);
        stack<string> st;
        for(int i = 0; i<v.size() ; i++){
            if(!st.empty() and v[i] == ".."){
                st.pop();
            }
            else if(st.empty() and v[i] == ".."){
                continue;
            }
            else if(v[i] == "." or v[i] == ""){
                continue;
            }
            else{
                st.push(v[i]);
            }
        }
        stack<string> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        string ans = "";
        while(!temp.empty()){
            ans += '/' + temp.top();
            temp.pop();
        }
        if(ans == ""){
            ans.push_back('/');
        }
        return ans;
    }
};