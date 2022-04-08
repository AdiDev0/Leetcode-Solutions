class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string ,int> m;
        for(auto it: emails){
            string str = it;
            string temp = "";
            int i = 0;
            while(str[i]!='@'){
                if(str[i]=='+'){
                    break;
                }
                if(str[i]=='.'){
                    i++;
                    continue;
                }
                temp.push_back(str[i++]);
            }
            while(str[i]!='@') i++;
            
            // cout<<temp<<" "<<str.substr(i+1, str.size()-i+1)<<endl;
            m[temp+'@'+str.substr(i+1, str.size()-i+1)]++;
        }
        return m.size();
    }
};