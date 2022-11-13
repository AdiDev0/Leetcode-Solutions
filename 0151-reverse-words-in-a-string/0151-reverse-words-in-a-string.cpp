class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        string ans = "";
        while(i<n){
            if(s[i]==' '){
                i++;
                continue;
            }
            j = i;
            string temp = "";
            while(s[j]!=' ' and j<n){
                temp.push_back(s[j]);
                j++;
            }
            reverse(temp.begin(), temp.end());
            ans.append(temp+" ");
            i = j;
        }
        ans.pop_back();
        reverse(ans.begin() , ans.end());
        return ans;
    }
};