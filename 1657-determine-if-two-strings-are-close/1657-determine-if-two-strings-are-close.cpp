class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n!=m) return false;
        map<char,int> m1,m2;
        for(int i = 0; i<n; i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        if(m1.size()!=m2.size()) return false;
        
        for(int i = 0; i<n; i++){
            if(!m2[word1[i]]) return false;
        }
        vector<int> temp(1000001, 0);
        for(auto it:m1){
            temp[it.second]++;
        } 
        int i = 0;
        for(auto it:m2){
            if(temp[it.second]==0){
                return false;
            }
            else{
                temp[it.second]--;
            }
        }
        return true;
    }
};