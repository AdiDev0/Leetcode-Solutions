class Solution {
public:
    bool isValid(vector<vector<int>>& heights,vector<vector<bool>> &ocean, int r, int c, int i, int j){
        int n = heights.size();
        int m = heights[0].size();
        if(i>=0 and i<n and j>=0 and j<m and ocean[i][j]==false and heights[r][c]<=heights[i][j]){
            return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& heights,vector<vector<bool>> &ocean, int n, int m, int row, int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        ocean[row][col] = true;
        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            int x[4] = {-1,0,1,0};
            int y[4] = {0,1,0,-1};
            for(int i = 0;i<4; i++){
                int nextRow = currRow+x[i];
                int nextCol = currCol+y[i];
                if(isValid(heights,ocean,currRow,currCol,nextRow,nextCol)){
                    ocean[nextRow][nextCol] = true;
                    q.push({nextRow,nextCol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        
        // for pacific
        for(int i = 0;i<m; i++){
            if(pacific[0][i] == false){
                bfs(heights,pacific,n,m,0,i);
            }
        }
        for(int i = 0; i<n; i++){
            if(pacific[i][0]==false){
                bfs(heights,pacific,n,m,i,0);
            }
        }
        // for atlantic
        for(int i = 0;i<m; i++){
            if(atlantic[n-1][i] == false){
                bfs(heights,atlantic,n,m,n-1,i);
            }
        }
        for(int i = 0; i<n; i++){
            if(atlantic[i][m-1]==false){
                bfs(heights,atlantic,n,m,i,m-1);
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
                else{
                }
            }
        }
        return ans;
        
    }
};