class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j){
        int n = grid.size();
        if(i>=0 and i<n and j>=0 and j<n and grid[i][j]==0){
            return true;
        }
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;
            if(currRow == n-1 and currCol == n-1){
                return grid[currRow][currCol];
            }
            int x[8] = {-1,0,1,1,1,0,-1,-1};
            int y[8] = {-1,-1,-1,0,1,1,1,0};
            for(int i = 0; i<8; i++){
                int nextRow = x[i]+currRow;
                int nextCol = y[i]+currCol;
                if(isValid(grid,nextRow,nextCol)){
                    grid[nextRow][nextCol] = grid[currRow][currCol]+1;
                    q.push({nextRow,nextCol});
                }
            }
        }
        return -1;
    }
};