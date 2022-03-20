class Solution {
public:
    int solve(vector<int>& t, vector<int>& b){
        int n = t.size();
        int val = t[0];
        int swaps = 0;
        for(int i = 0; i<n; i++){
            if(t[i]!=val){
                if(b[i]==val){
                    swaps++;
                }
                else{
                    return 1e8;
                }
            }
        }
        return swaps;
    }
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n = t.size();
        int ans = min(solve(t,b), solve(b,t));
        swap(t[0],b[0]); //1 swap is already done ..so +1.
        ans = min({ans, solve(t,b)+1, solve(b,t)+1});
        return ans==1e8?-1:ans;
    }
};