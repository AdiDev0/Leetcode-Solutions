class Solution {
public:
    bool isPossible(vector<int>& t) {
        int n = t.size();
        // vector<int> arr(n, 1);
        priority_queue<int> pq;
        long sum = 0;
        for(auto it: t){
            sum+=it;
            pq.push(it);
        }
        while(pq.top()!=1){
            int val = pq.top();
            pq.pop();
            sum-=val;
            if(sum==0 or sum>val) return false;
            int prevEle = val%sum;
            if(sum!=1 and prevEle==0) return false;
            sum+=prevEle;
            pq.push(prevEle);
        }
        return true;
    }
};