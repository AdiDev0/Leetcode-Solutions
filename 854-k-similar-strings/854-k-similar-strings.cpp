class Solution {
public:
    
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        queue<pair<string,int>>Q;
        unordered_set<string>seen;
        seen.insert(s1);
        Q.push({s1,0});
        
        while(not Q.empty()){
            auto [curr,steps] = Q.front();
            // cout << curr << " ";
            Q.pop();
            if(curr==s2)return steps;
            //match untill the match and find where is mismatched occured
            int i = 0;
            while(i < n and curr[i] == s2[i])i++;
            for(int j=i+1;j<n;j++){
                if(curr[j]==s2[i]){
                    swap(curr[j],curr[i]);
                    if(seen.count(curr)==0)Q.push({curr,steps+1}),seen.insert(curr);
                    swap(curr[j],curr[i]);
                }
            }
        }
        return 0;
    }
};