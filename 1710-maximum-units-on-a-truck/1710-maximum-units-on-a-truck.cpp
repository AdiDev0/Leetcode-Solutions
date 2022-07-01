class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& bt, int truckSize) {
        int n = bt.size();
        sort(bt.begin(), bt.end(), cmp);
        int currS = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(currS+bt[i][0]>truckSize){
                int rest = truckSize - currS;
                currS += rest;
                ans += rest*bt[i][1];
                break;
            }
            else{
                currS+=bt[i][0];
                ans += bt[i][0]*bt[i][1];
            }
        }
        return ans;
    }
};