class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string ,int> m;
        for(auto it: emails){
            string temp = "";
            int i = 0;
            while(it[i]!='@'){
                if(it[i]=='+'){
                    break;
                }
                if(it[i]=='.'){
                    i++;
                    continue;
                }
                temp.push_back(it[i++]);
            }
            while(it[i]!='@') i++;
            
            // cout<<temp<<" "<<it.substr(i+1, it.size()-i+1)<<endl;
            m[temp+'@'+it.substr(i+1, it.size()-i+1)]++;
        }
        return m.size();
    }
};