class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j] == 1){
            return true;
        }
        return false;
    }
    int bfs(vector<vector<int>>& grid, int currRow, int currCol){
        int area = 0;
        grid[currRow][currCol] = 0;
        queue<pair<int,int>> q;
        q.push({currRow,currCol});
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            area++;
            q.pop();
            int x[4] = {-1,0,1,0};
            int y[4] = {0,1,0,-1};
            for(int i = 0; i<4; i++){
                if(isValid(grid,a+x[i],b+y[i])){
                    q.push({a+x[i],b+y[i]});
                    grid[a+x[i]][b+y[i]] = 0;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea,bfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};