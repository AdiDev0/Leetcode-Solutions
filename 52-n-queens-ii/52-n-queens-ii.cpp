class Solution {
public:
    int ansCount = 0;
    bool canPlace(int n, vector<string> &ans, int row, int col){
        for(int i = 0; i<=row; i++){
            if(ans[i][col]=='Q') return false;
        }
        int i = row;
        int j = col;
        while(i-1>=0 and j-1>=0){
            if(ans[i-1][j-1]=='Q') return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        while(i-1>=0 and j+1>=0){
            if(ans[i-1][j+1]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(int n, vector<string> &ans, int row, int col){
        if(row==n){
            ansCount++;
            return;
        }
        for(int i = 0; i<n; i++){
            if(canPlace(n,ans, row, i)){
                ans[row][i] = 'Q';
                solve(n,ans,row+1,col);
                ans[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> ans(n, string(n,'.'));
        for(int i = 0; i<n; i++){
            ans[0][i] = 'Q';
            solve(n, ans, 1, i);
            ans[0][i] = '.';
        }
        return ansCount;
    }
};