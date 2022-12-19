//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& v, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: v){
            adj[it[0]].push_back({it[2], it[1]});
        }
        vector<int> vis(n+1, 1e9);
        vis[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int a = it.first;
                int b = it.second;
                if(a+dist < vis[b]){
                    vis[b] = a+dist;
                    pq.push({vis[b], b});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            ans = max(ans, vis[i]); 
        }
        return ans==1e9?-1:ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends