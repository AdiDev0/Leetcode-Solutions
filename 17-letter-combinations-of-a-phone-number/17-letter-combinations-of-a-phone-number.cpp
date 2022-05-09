// Time Complexity : O(4^N*N), where N, is the length of input string. 4^N for building every possible string combination and N to form the string by joining each character.. Here, 4 is chosen assuming the worst case where each digit will be 7 or 9 and we would have 4*4*4*4 total string combinations.

// Space Complexity : O(N), the max recursion depth will be N, where N is the length of input string. If the space required for ans is considered as well, the complexity will be O(4^N).

class Solution {
public:
    unordered_map<char, string> m;
    vector<string> ans;
    void solve(string &dig, string &temp, int index){
        if(temp.size() == dig.size()){
            ans.push_back(temp);
            return;
        }
        int i = index;
        while(i<dig.size()){
            for(auto it: m[dig[i]]){
                temp.push_back(it);
                solve(dig, temp, i+1);
                temp.pop_back();
            }
            i++;
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0) return ans;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string temp = "";
        solve(digits, temp, 0);
        return ans;
    }
};