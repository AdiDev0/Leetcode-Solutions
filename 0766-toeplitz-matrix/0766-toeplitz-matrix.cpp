class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++){
            int a = i;
            int b = 0;
            int val = matrix[a][b];
            while(a<n and b<m){
                if(val!=matrix[a][b]){
                    return false;
                }
                a++;
                b++;
            }
        }
        for(int j = 1; j<m; j++){
            int a = 0;
            int b = j;
            int val = matrix[a][b];
            while(a<n and b<m){
                if(val!=matrix[a][b]){
                    return false;
                }
                a++;
                b++;
            }
        }
        return true;
    }
};