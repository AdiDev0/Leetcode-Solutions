class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int i = 1;
        int m = 0;
        if(n%2==0){
            m = n/2;
        }
        else{
            m = (n-1)/2;
        }
        while(i<=m){
            ans.push_back(i);
            ans.push_back(-i);
            i++;
        }
        if(n%2!=0) ans.push_back(0);
        return ans;
    }
};