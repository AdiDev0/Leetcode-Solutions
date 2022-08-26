class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        vector<string> per;
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        unordered_set<string> st;
        int a = 0;
        while(true){
            long val = pow(2, a);
            if(val<=1e9){
                string str = to_string(val);
                sort(str.begin(), str.end());
                st.insert(str);
                a++;
            }
            else{
                break;
            }
        }
        return st.find(s)!=st.end();
    }
};