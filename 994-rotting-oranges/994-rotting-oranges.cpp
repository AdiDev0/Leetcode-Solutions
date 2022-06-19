class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int time = 0;
        
        while(!q.empty()){
            int qn = q.size();
            time++;
            for(int i = 0; i<qn; i++){
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if(x+1<n and grid[x+1][y]==1){
                    fresh--;
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                } 
                if(y+1<m and grid[x][y+1]==1){
                    fresh--;
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
                if(x-1>=0 and grid[x-1][y]==1){
                    fresh--;
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(y-1>=0 and grid[x][y-1]==1){
                    fresh--;
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
            }
        }
        if(fresh==0) return time-1;
        return -1;
    }
};