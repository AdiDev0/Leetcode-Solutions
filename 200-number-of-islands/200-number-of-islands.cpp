class Solution {
public:
    bool isSafe(vector<vector<char>> &v, int i, int j){
        int n = v.size();
        int m = v[0].size();
        if(i>=0 and i<n and j>=0 and j<m and v[i][j] == '1'){
            return true;
        }
        return false;
    }
    void bfs(vector<vector<char>> &v, int currRow, int currCol){
        queue<pair<int,int>> q;
        q.push({currRow,currCol});
        v[currRow][currCol] = '0';
        int x[4] = {-1,0,1,0};
        int y[4] = {0,1,0,-1};
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k = 0; k<4; k++){
                if(isSafe(v,i+x[k],j+y[k])){
                    v[i+x[k]][j+y[k]] = '0';
                    q.push({i+x[k],j+y[k]});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        int count = 0;
    
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(v[i][j] == '1'){
                    count++;
                    bfs(v,i,j);
                }
            }
        }
        return count;
    }
};