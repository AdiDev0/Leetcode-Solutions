class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> v(n, vector<int>(m,0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int live = 0;
                int dead = 0;
                if(i+1<n and board[i+1][j]==1) live++;
                if(i+1<n and board[i+1][j]==0) dead++;
                
                if(i+1<n and j+1<m and board[i+1][j+1]==0) dead++;
                if(i+1<n and j+1<m and board[i+1][j+1]==1) live++;
                
                if(j+1<m and board[i][j+1]==1) live++;
                if(j+1<m and board[i][j+1]==0) dead++;
                
                if(i-1>=0 and j+1<m and board[i-1][j+1]==1) live++;
                if(i-1>=0 and j+1<m and board[i-1][j+1]==0) dead++;
                
                if(i-1>=0 and board[i-1][j]==1) live++;
                if(i-1>=0 and board[i-1][j]==0) dead++;
                
                if(i-1>=0 and j-1>=0 and board[i-1][j-1]==1) live++;
                if(i-1>=0 and j-1>=0 and board[i-1][j-1]==0) dead++;
                
                if(j-1>=0 and board[i][j-1]==1) live++;
                if(j-1>=0 and board[i][j-1]==0) dead++;
                
                if(i+1<n and j-1>=0 and board[i+1][j-1]==0) dead++;
                if(i+1<n and j-1>=0 and board[i+1][j-1]==1) live++;
                
                if(board[i][j]==1 and (live==2 or live==3)) v[i][j] = 1;
                if(board[i][j]==0 and live==3) v[i][j] = 1;
                
            }
        }
        board = v;
    }
};