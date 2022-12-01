class Solution {
public:
    int cv(string s){
        int count = 0;
        for(auto it: s){
            count += it=='a' or it=='e' or it=='i' or it=='o' or it=='u' or it=='A' or it=='E' or it=='I' or it=='O' or it=='U';
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        return cv(s.substr(0, n/2))==cv(s.substr(n/2, n/2));
    }
};