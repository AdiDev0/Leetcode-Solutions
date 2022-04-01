class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n = s.size();
        unordered_map<string, string> m;
        for(int i = 0; i<k.size(); i++){
            m[k[i][0]] = k[i][1];
        }
        string ans = "";
        int i = 0;
        while(i<n){
            if(s[i]!='('){
                ans.push_back(s[i]);
            }
            else{
                int j = i+1;
                string temp = "";
                while(j<n and s[j]!=')'){
                    temp.push_back(s[j++]);
                }
                if(m.find(temp)!=m.end()){
                    ans.append(m[temp]);
                }
                else{
                    ans.push_back('?');
                }
                i = j+1;
                continue;
            }
            i++;
        }
        return ans;
    }
};