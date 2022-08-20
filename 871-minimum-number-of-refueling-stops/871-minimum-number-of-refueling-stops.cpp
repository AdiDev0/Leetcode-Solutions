class Solution {
public:
    int minRefuelStops(int target, int sf, vector<vector<int>>& s) {
        int n = s.size();
        int pos = sf;
        priority_queue<pair<int,int>> pq;
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i<n; i++){
            if(pos>=target){
                break;
            }
            while(!pq.empty() and pos<s[i][0]){
                pos += pq.top().first;
                cnt++;
                pq.pop();
            }
            if(pos<s[i][0]) return -1;
            pq.push({s[i][1], s[i][0]});
        }
        while(!pq.empty() and pos<target){
            pos += pq.top().first;
            cnt++;
            pq.pop();
        }
        if(pos<target){
            return -1;   
        }
        return cnt;
    }
};