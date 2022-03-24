class Solution {
public:
    bool solve(int val, vector<int> &pe, int limit){
        int n = pe.size();
        int high = n-1;
        int low = 0;
        int boats = 0;
        
        while(low<=high){
            if(pe[high]+pe[low]<=limit){
                low++;
                high--;
                val-=1;
            }
            else{
                if(high-low==1){
                    val-=2;
                    break;
                }
                high--;
                val--;
            }
        }
        if(val<0){
            return false;
        }
        return true;
    }
    int numRescueBoats(vector<int>& pe, int limit) {
        int n = pe.size();
        int low = 1;
        int high = n;
        
        sort(pe.begin(), pe.end());
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(solve(mid, pe, limit)){
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