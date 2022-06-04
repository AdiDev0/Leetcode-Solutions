class Solution {
public:
    vector<vector<string>> v;
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
    void solve(int n, vector<string> &ans, string &s, int row, int col){
        if(row==n){
            v.push_back(ans);
            return;
        }
        for(int i = 0; i<n; i++){
            if(canPlace(n,ans, row, i)){
                ans[row][i] = 'Q';
                solve(n,ans,s,row+1,col);
                ans[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans;
        string s = "";
        for(int i = 0; i<n; i++){
            s.push_back('.');
        }
        for(int i = 0; i<n; i++){
            ans.push_back(s);
        }
        for(int i = 0; i<n; i++){
            ans[0][i] = 'Q';
            solve(n, ans, s, 1, i);
            ans[0][i] = '.';
        }
        return v;
    }
};