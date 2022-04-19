class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> evenLR(n,0), oddLR(n,0), evenRL(n,0), oddRL(n,0);
        
        evenLR[0] = nums[0];
        for(int i = 1; i<n; i++){
            if(i%2==0){
                evenLR[i] += evenLR[i-1]+nums[i];
                oddLR[i]+=oddLR[i-1];
            }
            else{
                oddLR[i] += oddLR[i-1]+nums[i];
                evenLR[i] += evenLR[i-1];
            }
        }
        if((n-1)%2==0){
            evenRL[n-1] = nums[n-1];
        }
        else{
            oddRL[n-1] = nums[n-1];
        }
        for(int i = n-2; i>=0; i--){
            if(i%2==0){
                evenRL[i] += evenRL[i+1]+nums[i];
                oddRL[i]+=oddRL[i+1];
            }
            else{
                oddRL[i] += oddRL[i+1]+nums[i];
                evenRL[i] += evenRL[i+1];
            }
        }
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            if(evenLR[i-1]+oddRL[i+1]==oddLR[i-1]+evenRL[i+1]){
                ans++;
            }
        }
        if(n>1 and evenRL[1]==oddRL[1]) ans++;
        if(n-2>=0 and evenLR[n-2]==oddLR[n-2]) ans++;
        return ans;
    }
};