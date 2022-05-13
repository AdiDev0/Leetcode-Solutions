// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    bool isValid(vector<vector<int>> &grid,vector<vector<int>> &vis,int n,int i,int j){
        if(i>=0 and i<n and j>=0 and j<n and grid[i][j]==1 and vis[i][j]==-1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &grid, int n, string &s,int row,int col,vector<vector<int>> &vis){
        if(row==n-1 and col==n-1){
            // cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,1,-1};
        for(int i = 0; i<4; i++){
            int nextRow = row+x[i];
            int nextCol = col+y[i];
            if(isValid(grid,vis,n,nextRow,nextCol)){
                vis[nextRow][nextCol] = 1;
                if(i==0) s.push_back('U');
                if(i==1) s.push_back('D');
                if(i==2) s.push_back('R');
                if(i==3) s.push_back('L');
                solve(grid,n,s,nextRow,nextCol,vis);
                vis[nextRow][nextCol] = -1;
                s.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        string s = "";
        if(grid[0][0]==0) return ans;
        vector<vector<int>> vis(n,vector<int>(n,-1));
        vis[0][0] = 1;
        solve(grid,n,s,0,0,vis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends