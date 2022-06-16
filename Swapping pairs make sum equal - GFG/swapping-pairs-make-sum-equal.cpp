// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m){
	    sort(A,A+n);
	    sort(B,B+m);
	    int sumA = 0;
	    int sumB = 0;
	    for(int i = 0; i<n; i++){
	        sumA+=A[i];
	    }
	    for(int i = 0; i<m; i++){
	        sumB+=B[i];
	    }
	   // if(sumA<sumB){
	   //     return findSwapValues(B,m,A,n);
	   // }
	    int ogap = abs(sumA-sumB);
        for(int i = 0; i<n; i++){
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                int ele = B[mid];
                int diff = A[i]-ele;
                int gap = (sumA-diff) - (sumB+diff);
                if(gap==0) return 1;
                if(gap<0) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends