class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = m-1;
        int direction = 0;
        while(top<=down and left<=right){
            if(direction==0){
                for(int i = left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(direction==1){
                for(int i = top; i<=down; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(direction==2){
                for(int i = right; i>=left; i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(direction==3){
                for(int i = down; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return ans;
    }
};