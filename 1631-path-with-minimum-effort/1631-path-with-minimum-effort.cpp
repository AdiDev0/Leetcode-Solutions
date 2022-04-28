class Solution {
public:
    int x[4] = {-1,0,1,0};
    int y[4] = {0,-1,0,1};
    bool isValid(int i , int j , vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        if(i>=0 and i<n and j>=0 and j<m){
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0] = 0;
        pq.push({0,0,0}); // {prevMaxEffort , currRow , currCol}
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int prevMaxEffort = temp[0];
            int currRow = temp[1];
            int currCol = temp[2];
            
            for(int i = 0; i<4;i++){
                int nextRow = currRow + x[i];
                int nextCol = currCol + y[i];
                
                if(isValid(nextRow,nextCol,heights)){
                    
                    int currEffort = abs(heights[nextRow][nextCol]-heights[currRow][currCol]);
                    currEffort = max(currEffort, prevMaxEffort);
                    
                    if(currEffort < effort[nextRow][nextCol]){
                        effort[nextRow][nextCol] = currEffort;
                        pq.push({currEffort , nextRow, nextCol});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};