class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = -1;
        string word;
        vector<string> words; //a vector to store every word
        for(int i = 0; i < sentence.size(); i++){
            if (sentence[i] != ' '){
                word += sentence[i];
            }
            else{
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);//the last word doesnt end with ' ', add the last word in
        int k = 0;
        int n = searchWord.size();
        for (int j = 0; j < words.size(); j++){
            for (; k < n; k++){
                if (searchWord[k] != words[j][k]){
                    k=0;
                    break;
                }
                else if (k == (n-1)){
                    res = j + 1; // return the 1-indexed, not 0-indexed.
                }
            }
        }
        
        return res;
    }
};