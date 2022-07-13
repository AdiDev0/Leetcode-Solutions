// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(const struct Job &a, const struct Job &b){ 
       if(a.dead != b.dead)return (a.dead < b.dead);
       return(a.profit < b.profit); 
    }
    vector<int> JobScheduling(Job a[], int n) { 
        sort(a, a+n, comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i<n; i++){
            pq.push(a[i].profit);
            while(pq.size()>a[i].dead){
                pq.pop();
            }
        }
        int count = pq.size();
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return {count, ans};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends