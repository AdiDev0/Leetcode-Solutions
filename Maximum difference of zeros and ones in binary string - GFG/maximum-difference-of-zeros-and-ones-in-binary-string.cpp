// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s){
	    int n = s.size();
	    vector<int> v;
	    for(int i = 0; i<n; i++){
	        if(s[i]=='0') v.push_back(-1);
	        else v.push_back(1);
	    }
	    
	    int ans = v[0];
	    int currSum = v[0];
	    bool haszero = false;
	    if(v[0]==-1) haszero = true;
	    for(int i = 1; i<n; i++){
	        if(v[i]==-1) haszero = true;
	        if(currSum+v[i]<0){
	            currSum+=v[i];
	        }
	        else{
	            currSum = v[i];
	        }
	        ans = min(currSum, ans);
	    }
	    if(haszero) return abs(ans);
	    return -1;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends