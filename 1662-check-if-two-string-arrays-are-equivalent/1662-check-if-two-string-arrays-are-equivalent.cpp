class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for(string &it:word1){
            a.append(it);
        }
        for(string &it:word2){
            b.append(it);
        }
        return a==b;
    }
};