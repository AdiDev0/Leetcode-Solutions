class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        unordered_map<char, vector<int>> m;
        
        for(int i = 0; i<n; i++){
            string s = votes[i];
            for(int j = 0; j<s.size(); j++){
                if(m[s[j]].size()==0){
                    vector<int> v(27, 0);
                    m[s[j]] = v;
                    m[s[j]][j+1]++;
                }
                else{
                    m[s[j]][j+1]++;
                }
            }
        }
        
        string s = "";
        for(auto it: m){
            s.push_back(it.first);
        }
        
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                vector<int> a = m[s[i]];
                vector<int> b = m[s[j]];
                bool swapped = false;
                for(int k = 1; k<=26; k++){
                    if(a[k]<b[k]){
                        swapped = true;
                        swap(s[i],s[j]);
                        break;
                    }
                    else if(a[k]>b[k]){
                        swapped = true;
                        break;
                    }
                }
                if(!swapped){
                    if(s[j]<s[i]){
                        swap(s[i],s[j]);
                    }
                }
            }
        }
        return s;
    }
};