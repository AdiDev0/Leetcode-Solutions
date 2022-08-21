class Solution {
public:
    int longestPalindrome(string num) {
        int n = num.size();
        if(n==0) return 0;
        unordered_map<char,int> m;
        for(auto it: num){
            m[it]++;
        }
        priority_queue<pair<char,int>> pq, pqo;
        for(auto it: m){
            pq.push({it.first, it.second});
            if(it.second%2!=0){
                pqo.push({it.first, it.second});
            }
        }
        char maxOdd = ' ';
        int maxF = 0;
        if(pqo.size()){
            maxOdd = pqo.top().first;
            maxF = pqo.top().second;
        }
        string st = "";
        string end = "";
        while(!pq.empty()){
            char ch = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            if(freq%2==0){
                int a = freq/2;
                while(a--){
                    st.push_back(ch);
                    end.push_back(ch);
                }
            }
            else{
                int a = (freq-1)/2;
                while(a--){
                    st.push_back(ch);
                    end.push_back(ch);
                }
            }
        }
        // while(maxF--){
            if(maxOdd!=' '){
                st.push_back(maxOdd);
            }
        // }
        reverse(end.begin(), end.end());
        string s = st+end;
        
        return s.size();
    }
};