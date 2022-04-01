class Solution {
public:
    bool solve(vector<int> &bd, int maxDays, int m, int k){
        int n = bd.size();
        int i = 0;
        while(i+k<=n){
            int j = i;
            int maxi = 0;
            int maxInd = -1;
            while(j<n and j<i+k){
               if(maxi<bd[j]){
                   maxi = bd[j];
                   maxInd = j;
               }
                j++;
            }
            if(maxi<=maxDays){
                m--;
            }
            else{
                i = maxInd+1;
                continue;
            }
            i = j;
        }
        if(m>0) return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = INT_MIN;
        for(auto it: bloomDay) maxi = max(maxi, it);
        
        int low = 1;
        int high = maxi;
        int ans = -1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            // cout<<mid<<" ";
            if(solve(bloomDay, mid, m, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};