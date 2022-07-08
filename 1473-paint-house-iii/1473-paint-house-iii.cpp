class Solution {
public:
    //declare dp of size m*m*n (the max possible)
    int dp[100][100][21];
    
    const int mx = 1e7+1;
    int f(vector<int>& houses, vector<vector<int>>& cost, int target, int idx, int count, int prev){
        //base cases
        if(idx == houses.size()) return count==target ? 0 : mx;
        if(idx > houses.size()) return mx;
        
        //memoization
        if(dp[idx][count][prev]!=-1) return dp[idx][count][prev];
        
        int minCost = mx;
        //If already painted
        if(houses[idx]){
            
            //if prev house is of different color, increase the count by 1
            if(houses[idx]!=prev) minCost = f(houses,cost,target,idx+1,count+1,houses[idx]);
            
            else minCost = f(houses,cost,target,idx+1,count,houses[idx]);
            
        }else{
            //we have to try all the colors
            for(int j=0;j<cost[0].size();j++){
                int tmp;  //store the current cost
                
                //if prev house is of different color, increase the count by 1
                if((j+1)!=prev) tmp = cost[idx][j] + f(houses,cost,target,idx+1,count+1,j+1);
                
                else tmp = cost[idx][j] + f(houses,cost,target,idx+1,count,j+1);
                
                minCost = min(minCost,tmp);
            }
        }
        //store before returning
        return dp[idx][count][prev] = minCost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        
        // 0 0 0 represents the current index(idx) , neighbourhood count(count), color of prev house(prev)
        int ans = f(houses,cost,target,0,0,0);
        
        //if no solution exist
        if(ans==mx) return -1;
        else return ans;
    }
};


// class Solution {
// public:
//     int ans = INT_MAX;
//     int solve(vector<int>& h, vector<vector<int>>& cost, int m, int n, int k, int i, int j, int currCost,int lastC, vector<vector<vector<int>>> &dp){
        
//         if(k<0) return -1;
//         if(i==m and k==0) return 0;
//         if(i==m and k!=0) return -1;
//         if(dp[i][j][k]!=-1) return dp[i][j][k];
        
//         int val = 0;
//         if(h[i]!=0){
//             if(lastC==h[i]){
//                 val = solve(h,cost,m,n,k,i+1,0,currCost,lastC,dp);
//             }
//             else{
//                 val = solve(h,cost,m,n,k-1,i+1,0,currCost,h[i]-1,dp);
//             }
//             return dp[i][j][k] = val;
//         }
//         else{
//             if(j<n-1){
//                 if(cost[i][j]==lastC){
//                     val = solve(h,cost,m,n,k,i,j+1,currCost, lastC, dp);
//                 }
//                 else{
//                     val = cost[i][j] + solve(h,cost,m,n,k-1,i,j+1,currCost, j, dp);
//                 }
//             }
//             else{
//                 if(cost[i][j]==lastC){
//                     val = solve(h,cost,m,n,k,i+1,0,currCost, lastC, dp);
//                 }
//                 else{
//                     val = solve(h,cost,m,n,k-1,i+1,0,currCost, j, dp);
//                 }
//             }
//         }
//         return dp[i][j][k] = val;
//     }
//     int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) {
//         vector<vector<vector<int>>> dp(m+1, vector<int>(n+1, vector<int>(target+1,-1)));
//         return solve(h, cost, m, n, target,0,0,0,0,dp);
//     }
// };