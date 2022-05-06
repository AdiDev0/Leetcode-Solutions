class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;
        int i = 0;
        while(i<n){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                if(s[i]==st.top().first){
                    auto temp = st.top();
                    int prevFreq = temp.second;
                    int j = i;
                    int count = 0;
                    while(j<n and s[j]==s[i]){
                        count++;
                        if(count+prevFreq==k){
                            break;
                        }
                        j++;
                    }
                    if(count+prevFreq==k){
                        st.pop();
                        i = j+1;
                        continue;
                    }
                    else{
                        st.top().second+=count;
                        i = j;
                        continue;
                    }
                }
                else{
                    st.push({s[i],1});
                }
            }
            i++;
        }
        string str = "";
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            int freq = temp.second;
            int c = temp.first;
            while(freq--){
                str.push_back(c);
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};