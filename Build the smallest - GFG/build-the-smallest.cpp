//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string s, int k){
    int n = s.size();
    stack<char> st;
    
    for(auto it: s){
        if(st.empty()){
            st.push(it);
        }
        else{
            while(!st.empty() and st.top()>it and k>0){
                st.pop();
                k--;
            }
            st.push(it);
        }
    }
    while(k--){
        st.pop();
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    int i = 0;
    int m = ans.size();
    while(i<m and ans[i]=='0'){
        i++;
    }
    int len = m-i;
    if(i==m) return "0";
    return ans.substr(i, m-i);
    
}