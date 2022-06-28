class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        priority_queue<int> pq;
        sort(s.begin(), s.end());
        int i = 0;
        while(i<n){
            int j = i;
            while(j<n and s[i]==s[j]){
                j++;
            }
            pq.push(j-i);
            i = j;
        }
        int ans = 0;
        while(pq.size()>1){
            int val = pq.top();
            pq.pop();
            int f = pq.top();
            if(val!=f){
                continue;
            }
            val--;
            ans++;
            if(val>0) pq.push(val);
        }
        return ans;
    }
};