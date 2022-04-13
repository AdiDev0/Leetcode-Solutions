class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        int start = 1;
        vector<int> ans;
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int direction = 0;
        while(top<=down and left<=right){
            if(direction==0){
                for(int i = left; i<=right; i++){
                    matrix[top][i] = start++;
                }
                top++;
            }
            else if(direction==1){
                for(int i = top; i<=down; i++){
                    matrix[i][right] = start++;
                }
                right--;
            }
            else if(direction==2){
                for(int i = right; i>=left; i--){
                    matrix[down][i] = start++;
                }
                down--;
            }
            else if(direction==3){
                for(int i = down; i>=top; i--){
                    matrix[i][left] = start++;
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return matrix;
    }
};