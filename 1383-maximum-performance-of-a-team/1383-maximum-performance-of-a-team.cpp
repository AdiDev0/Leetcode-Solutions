class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& e, int k) {
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<n; i++){
            v.push_back({e[i], speed[i]});
        }
        sort(v.begin(), v.end());
        
        k--;
        
        long ans = 0;
        long pSum = 0;
        int mod = 1e9+7;
        for(int i = n-1; i>=0; i--){
            int val = v[i].second;
            long currAns = (long)v[i].first*((long)pSum+val);
            ans = max(ans, currAns);
            // cout<<val<<" "<<pSum<<" "<<v[i].first<<endl;
            pq.push(v[i].second);
            pSum+=v[i].second;
            if(pq.size()>k){
                auto temp = pq.top();
                pq.pop();
                pSum-=temp;
            }
        }
        return ans%mod;
    }
};

// 2 3 4  5 7 9
// 8 3 10 7 5 1   34