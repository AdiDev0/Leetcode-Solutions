class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        
        for(int i = 0; i<amount+1; i++){
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int j = 1 ; j<amount+1 ; j++){
            
            for(int k = 0; k<coins.size() ; k++){
                if(coins[k] <= j){
                    int reqCoins = dp[j-coins[k]];
                    if(reqCoins!=INT_MAX){
                        dp[j] = min(dp[j] , reqCoins+1);
                    }
                }
            }
        }
            
        if(dp[amount] == INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};