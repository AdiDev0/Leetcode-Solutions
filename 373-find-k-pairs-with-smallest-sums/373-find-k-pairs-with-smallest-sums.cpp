class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k){
        int n = a.size();
        int m = b.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        set<pair<int,int>> s, ansSet;
        vector<vector<int>> ans;
        
        pq.push({a[0]+b[0], {0,0}});
        s.insert({0,0});
        while(k--){
            auto t = pq.top();
            pq.pop();
            
            int sum = t.first;
            int x = t.second.first;
            int y = t.second.second;
            // cout<<x<<" "<<y<<endl;
            if(ansSet.find({x,y})==ansSet.end()){
                ans.push_back({a[x],b[y]});
                ansSet.insert({x,y});
            }
            
            if(x<n-1 and y<m and s.find({x+1,y})==s.end()){
                pq.push({a[x+1]+b[y], {x+1,y}});
                s.insert({x+1,y});
            }
            if(x<n and y<m-1 and s.find({x,y+1})==s.end()){
                pq.push({a[x]+b[y+1], {x,y+1}});
                s.insert({x,y+1});
            }
        }
     
        return ans;
    }
};