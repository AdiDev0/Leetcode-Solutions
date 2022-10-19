class Solution {
public:
    static bool cmp(pair<int, string> &a, pair<int, string> &b){
        if(a.first == b.first){
            return a.second<=b.second;
        }
        return a.first >= b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string ,int> m;
        vector<pair<int, string>> v;
        vector<string> ans;
        priority_queue<pair<int , string>> pq;
        for(int i = 0; i<n; i++){
            m[words[i]]++;
        }
        for(auto it:m){
            pq.push({it.second , it.first});
        }
        while(!pq.empty()){
            v.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        
        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};