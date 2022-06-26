class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int totalSum = 0;
        for(int i = 0; i<n; i++){
            totalSum+=card[i];
        }
        if(k==n){
            return totalSum;
        }
        int subarray = n-k;
        int currSum = 0;
        int minSum = INT_MAX;
        int i = 0;
        for(; i<subarray; i++){
            currSum+=card[i];
        }
        i=0;
        minSum = currSum;
        int j = subarray;
        while(j<n){
            currSum = currSum+card[j]-card[i];
            minSum = min(minSum,currSum);
            j++;
            i++;
        }
        return totalSum - minSum;
    }
};