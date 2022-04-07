class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.size();
        vector<int> closeLeft(n,-1), closeRight(n,n), prefix(n,0), ans;
        
        if(s[0]=='|') closeLeft[0] = 0;
        if(s[n-1]=='|') closeRight[n-1] = n-1;
        
        for(int i = 1; i<n; i++){
            if(s[i]=='|') closeLeft[i] = i;
            else closeLeft[i] = closeLeft[i-1];
        }
        
        for(int i = n-2; i>=0; i--){
            if(s[i]=='|') closeRight[i] = i;
            else closeRight[i] = closeRight[i+1];
        }
        
        // for(int i = 0; i<n; i++){
        //     cout<<closeLeft[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i<n; i++){
        //     cout<<closeRight[i]<<" ";
        // }
        // cout<<endl;
        if(s[0]=='*') prefix[0] = 1;
        
        for(int i = 1; i<n; i++){
            if(s[i]=='*') prefix[i] += prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }
        
        for(int i = 0; i<q.size(); i++){
            int a = q[i][0];
            int b = q[i][1];
            
            if(closeRight[a]!=n and closeLeft[b]!=-1 and closeRight[a]<closeLeft[b]){
                ans.push_back(prefix[closeLeft[b]] - prefix[closeRight[a]]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};