class Solution {
public:
    int uniqueLetterString(string s) {
        long long n = s.size();
        long long ans = 0;
        unordered_map<int,int> lastOcc;
        
        unordered_map<char,vector<int>> m;
        for(int i = 0; i<n; i++){
            lastOcc[s[i]-'A'] = -1;
            m[s[i]].push_back(i);
        }
        for(long long i = 0; i<n; i++){
            int ind = s[i] - 'A';
            auto next = upper_bound(m[s[i]].begin(), m[s[i]].end(), i) - m[s[i]].begin();
            if(m[s[i]].size()==next){
                ans += (n-i)*(i-lastOcc[ind]);
            }
            else{
                ans += (m[s[i]][next]-i)*(i-lastOcc[ind]);
            }
            lastOcc[ind] = i;
        }
        return ans;
    }
};