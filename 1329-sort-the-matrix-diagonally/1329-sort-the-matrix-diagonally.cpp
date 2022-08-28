class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++){
            int a = i;
            int b = 0;
            vector<int> temp;
            while(a<n and b<m){
                temp.push_back(mat[a++][b++]);
            }
            sort(temp.begin(), temp.end());
            a = i;
            b = 0;
            int k = 0;
            while(a<n and b<m){
                mat[a][b] = temp[k++];
                a++;
                b++;
            }
        }
        
        for(int j = 1; j<m; j++){
            int a = 0;
            int b = j;
            vector<int> temp;
            while(a<n and b<m){
                temp.push_back(mat[a++][b++]);
            }
            sort(temp.begin(), temp.end());
            a = 0;
            b = j;
            int k = 0;
            while(a<n and b<m){
                mat[a][b] = temp[k++];
                a++;
                b++;
            }
        }
        return mat;
    }
};