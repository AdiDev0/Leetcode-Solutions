class Solution {
public:
    vector<string> getFiles(string &s){
        int n = s.size();
        vector<string> v;
        int j = 0;
        while(j<n and s[j]!=' '){
            j++;
        }
        j++;
        int i = j;
        while(i<n){
            j = i;
            while(j<n and s[j]!=' '){
                j++;
            }
            v.push_back(s.substr(i, j-i));
            i = j+1;
        }
        for(auto ii: v){
            cout<<ii<<endl;
        }
        // cout<<endl;
        return v;
    }
    string getPrestring(string &s){
        int n = s.size();
        int i = 0;
        while(i<n and s[i]!=' '){
            i++;
        }
        return s.substr(0, i);
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        int cnt = 0;
        
        for(int k = 0; k<n; k++){
            string it = paths[k];
            string pre = getPrestring(it);
            // cout<<pre<<endl;
            vector<string> v = getFiles(it);
            cnt+=v.size();
            for(auto x: v){
                int l = x.size();
                int i = 0;
                while(i<l and x[i]!='('){
                    i++;
                }
                int j = i;
                while(j<l and x[j]!=')'){
                    j++;
                }
                
                m[x.substr(i, j-i+1)].push_back(pre+'/'+x.substr(0,l-(j-i+1)));
            }
        }
        for(auto it: m){
            if(it.second.size()<=1) continue;
            ans.push_back(it.second);
            // cout<<it.first<<" -> ";
            // for(auto i:it.second){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
        }
        if(ans.size()==cnt) return {};
        return ans;
    }
};