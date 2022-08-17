class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> m;
        for(auto it: words){
            string s = it;
            string temp = "";
            for(int i = 0; i<s.size(); i++){
                temp += code[s[i]-'a'];
            }
            m.insert(temp);
        }
        return m.size();
    }
};