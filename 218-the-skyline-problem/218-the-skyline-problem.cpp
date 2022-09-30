class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        int n = b.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int, vector<pair<int,int>> > m;
        set<int> s;
        
        for(int i = 0; i<n; i++){
            int l = b[i][0];
            int r = b[i][1];
            int h = b[i][2];
            m[l].push_back({h,r});
            s.insert(l);
            s.insert(r);
        }
        int lastHeight = -1;
        vector<vector<int>> ans;
        for(auto it: s){
            int c = it;
            while(!pq.empty() and pq.top().second<=c){
                pq.pop();
            }
            for(auto i: m[c]){
                pq.push(i);
            }
            int currHeight = -1;
            if(pq.empty()){
                currHeight = 0;
            }
            else{
                currHeight = pq.top().first;
            }
            if(lastHeight!=currHeight){
                ans.push_back({c, currHeight});
                lastHeight = currHeight;
            }
        }
        return ans;
    }
};