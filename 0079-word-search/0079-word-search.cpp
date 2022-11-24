class Solution {
public:
    // string str = "";
    
    bool isValid(vector<vector<char>>& board,int i,int j,int index,string word,vector<vector<int>>&vis){
        int m = board.size();
        int n = board[0].size();
        if(i>=0 and i<m and j>=0 and j<n and vis[i][j] == -1 and board[i][j] == word[index]){
            return true;
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int index,int currRow,int currCol,vector<vector<int>>&vis){
        if(index==word.size()){
            return true;
        }
        int x[4]={-1,0,1,0};
        int y[4] = {0,-1,0,1};
        for(int i = 0; i<4; i++){
            int nextRow = currRow + x[i];
            int nextCol = currCol + y[i];
            if(isValid(board , nextRow , nextCol, index,word,vis)){
                vis[nextRow][nextCol] = 1;
                if(search(board,word,index+1,nextRow,nextCol,vis)){
                    return true;
                }
                vis[nextRow][nextCol] = -1;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int s = word.size();
        if(m*n<s){
            return false;
        }
        vector<vector<int>>vis(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(search(board ,word,1,i,j,vis)){
                        return true;
                    }
                    vis[i][j] = -1;
                }
            }
        }
        return false;
    }
};