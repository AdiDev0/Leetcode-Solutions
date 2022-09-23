class Solution {
public:
     int minInsertions(string t) {
        int ans=0;
        stack<char> s;
        int n = t.length();
        for(int i=0;i<n;i++){
            char c = t[i];
            if(c=='(')
                s.push('(');
            else{
                if(s.empty()){
                    if(i+1<n && t[i+1]==')')
                        ans++,i++;
                    else
                        ans+=2;
                }
                else{
					s.pop();
                    if(i+1<n && t[i+1]==')') i++;
                    else ans++;					
                }
            }
        }
        
        while(!s.empty()){
            s.pop();
            ans+=2;
        }
        return ans;
//     int minInsertions(string s) {
//         int n = s.size();
        
//         stack<int> st;
//         int extra = 0;
//         int ans = 0;
        
//         for(int i = 0; i<n; i++){
//             if(s[i]==')'){
//                 if(st.empty()){
//                     extra++;
//                 }
//                 else{
//                     st.top()--;
//                     if(st.top()==0) st.pop();
//                 }
//             }
//             else{
//                 if(!st.empty() and st.top()==1){
//                     ans++;
//                     st.pop();
//                 }
//                 st.push(2);
//             }
//         }
        
//         while(!st.empty()){
//             ans+=st.top();
//             st.pop();
//         }
        
//         if(extra%2!=0){
//             ans += 2;
//         }
//         return ans+extra/2;
    }
};