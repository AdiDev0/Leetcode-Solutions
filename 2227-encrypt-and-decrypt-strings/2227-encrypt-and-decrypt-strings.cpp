class Encrypter {
public:
    map<char,string> m;
    map<string,int> com;
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        for(int i=0; i<k.size(); ++i){
            m[k[i]] = v[i];
        }
        
        for(int i=0; i<d.size(); ++i){
            string ans = "";
            for(int j=0; j<d[i].size(); ++j){
                ans+=m[d[i][j]];
            }
            com[ans]++;
        }
    }
    
    string encrypt(string s) {
        
        string ans = "";
        
        for(int i=0; i<s.size(); ++i){
            ans+=m[s[i]];
        }
        
        return ans;
        
    }
    
    int decrypt(string s) {
        
        if(com.count(s))
            return com[s];
        
        return 0;
        
    }
};