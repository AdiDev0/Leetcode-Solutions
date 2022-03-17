class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int totScore = 0;
        vector<pair<int,int>> v(51,{0,0});
        
        for(int i = 0; i<n; i++){
            if(st.empty() or s[i]=='('){
                st.push(i);
            }  
            else{
                // s[i]==')'
                int currScore = 0;
                if(i-st.top()==1){
                    v[st.top()] = {i,1};
                }
                else{
                    int j = st.top()+1;
                    while(j<i){
                        if(s[j]=='('){
                            currScore+=v[j].second;
                            j = v[j].first;
                        }
                        j++;
                    }
                    v[st.top()] = {i, 2*currScore};
                }
                st.pop();
            }
        }
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                totScore += v[i].second;
                i = v[i].first;
            }
            i++;
        }
        return totScore;
    }
};

// "()(())"
// "(()()(()))"
// "((()())()()((()())))"
// "((()()))"