class Solution {
public:
    string largestWordCount(vector<string>& mess, vector<string>& send) {
        int n = mess.size();
        map<string, int> m;
        
        for(int i = 0; i<n; i++){
            string s = mess[i];
            int cnt = 1;
            for(auto it: s){
                cnt += it==' ';
            }
            m[send[i]] += cnt;
        }
        int maxi = -1;
        string ans = "";
        for(auto it: m){
            if(it.second>maxi){
                maxi = it.second;
                ans = it.first;
            }
            else if(it.second==maxi){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};