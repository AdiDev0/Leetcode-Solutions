

class Solution
{
    public:
    vector<int> ans;
    int target = 0;
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        vector<int> res(12, 0);
        rec(11, numArrows, aliceArrows, 0, res);
        return ans;
    }
    void rec(int n, int numArrows, vector<int> &aliceArrow, int sum, vector<int> res)
    {
        if (n == -1 || numArrows <= 0)
        {
            if (sum > target)
            {
                target = sum;
                if (numArrows > 0)
                {
                    res[0] += numArrows;
                }
                ans = res;
            }
            return;
        }
        int req = aliceArrow[n] + 1;
        if (req <= numArrows)
        {
            res[n] = req;
            rec(n - 1, numArrows - req, aliceArrow, sum + n, res);
            res[n] = 0;
        }
        rec(n - 1, numArrows, aliceArrow, sum, res);
        return;
    }
};

// class Solution {
// public:
//     vector<int> ans;
//     int maxScore = 0;
//     void solve(int tot, vector<int> &a, vector<int> &b, int ind, int currS){
//         if(ind==-1 or currS == tot){
//             int score = 0;
//             for(int j = 0; j<b.size(); j++){
//                 if(b[j]!=0){
//                     score+=j;
//                 }
                
//             }
//             if(maxScore<score){
//                 maxScore = score;
//                 ans = b;
//                 if(currS<tot){
//                     ans[0]+=tot-currS;
//                 }
//             }
//             return;
//         }
//         if(currS>tot) return;
//         int i = ind;
//         while(i>=0){
//             // if(currS+(a[i]+1)<=tot){
//                 currS += a[i]+1;
//                 b[i] = a[i]+1;
//                 solve(tot, a,b, i-1, currS);
//                 currS -= a[i]+1;
//                 b[i] = 0;
//             // }
//             i--;
//         }
//     }
//     vector<int> maximumBobPoints(int tot, vector<int>& a) {
//         int n = a.size();
//         vector<int> b(n,0);
//         solve(tot,a,b,n-1,0);
//         return ans;
//     }
// };