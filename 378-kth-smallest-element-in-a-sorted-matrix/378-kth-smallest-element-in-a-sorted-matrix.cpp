class Solution{
public:
    int rank(vector<vector<int>> &mat, int n,int target){
        int i=n-1;
        int j=0;
        int count=0;
        while(i>=0 && j<n){
            if(mat[i][j]<=target){
                count += i+1;
                j++;
            }
            else{
                i--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k){
        
        int n=mat.size();
        int low=mat[0][0];
        int high=mat[n-1][n-1];
        
        while(low<high){
            int mid=low-(low-high)/2;
            int res=rank(mat,n,mid);
            // cout<<mid<<" "<<res<<endl;
            if(res>=k)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};