class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i<n; i++){
            int gap = h[i]-h[i-1];
            if(gap<0) continue;
            pq.push(gap);
            if(pq.size()>l){
                b-=pq.top();
                pq.pop();
            }
            if(b<0) return i-1;
        }
        return n-1;
    }
};