class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    int mostBooked(int room, vector<vector<int>>& meet) {
        int n = meet.size();
        sort(meet.begin(), meet.end(), compare);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> rpq;
        
        vector<int> v(room+1, 0);
        int j = 0;
        while(j<room) rpq.push(j++);
        
        for(int i = 0; i<n; i++){
            int s = meet[i][0];
            int e = meet[i][1];
            
            while(!pq.empty() and pq.top().first<=s){
                rpq.push(pq.top().second);
                pq.pop();
            }
            
            if(rpq.size()>0){ // this means we have rooms avalible for this meeting
                int r = rpq.top();
                rpq.pop();
                v[r]++;
                pq.push({e,r});
            }
            else{
                // if room is not avalible then we will add this meeting time into a existing meeting time
                long long t = pq.top().first + (e-s);
                int r = pq.top().second;
                pq.pop();
                v[r]++;
                pq.push({t, r});
            }
        }
        int ans = 0;
        for(int i = 0; i<=room; i++){
            if(v[ans]<v[i]){
                ans = i;
            }
        }
        return ans;
    }
};