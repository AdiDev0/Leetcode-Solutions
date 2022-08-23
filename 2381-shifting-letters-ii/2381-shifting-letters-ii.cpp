class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.size();
        vector<int> v(n, 0);
        
        for(auto it: sh){
            int start = it[0];
            int end = it[1];
            int d = it[2];
            if(d==1){
                v[start]+=1;
                if(end<n-1){
                    v[end+1] += -1;
                }
            }
            else{
                v[start] += -1;
                if(end<n-1){
                    v[end+1] += 1;
                }
            }
        }
        
        for(int i = 1; i<n; i++){
            v[i] += v[i-1];
        }
        
        for(int i = 0; i<n; i++){
            int k = v[i]%26;
            s[i] = 'a' + (s[i]-'a'+k+26)%26;
        }
        return s;
    }
};