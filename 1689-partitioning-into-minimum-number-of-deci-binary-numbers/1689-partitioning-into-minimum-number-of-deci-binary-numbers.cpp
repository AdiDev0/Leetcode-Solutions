class Solution {
public:
    char findMin(string &s){
        int n = s.size();
        char mini = '9';
        bool hasnine = false;
        for(auto it: s){
            if(it=='0') continue;
            mini = min(mini, it);
            if(it=='9') hasnine = true;
        }
        if(mini=='9' and !hasnine){
            return '0';
        }
        return mini;
    }
    int minPartitions(string s) {
        int n = s.size();
        int ans = 0;

        while(findMin(s)!='0'){
            char mini = findMin(s);
            ans+=mini-'0';
            string str = "";
            int i = n-1;
            while(i>=0){
                if(s[i]=='0'){
                    str.push_back('0');
                }
                else{
                    int temp = s[i]-mini;
                    str += to_string(temp);
                }
                i--;
            }
            reverse(str.begin(), str.end());
            s = str;
        }
        return ans;
    }
};