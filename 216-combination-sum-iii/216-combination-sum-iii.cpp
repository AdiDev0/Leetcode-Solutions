class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &v, int k, int target,vector<int> &temp, int &sum,int index){
        if(temp.size()==k and sum==target){
            ans.push_back(temp);
            return;
        }
        // if(sum>target or temp.size()>k) return;
        int i = index;
        while(i<9){
            if(sum+v[i]<=target and temp.size()<k){
                sum+=v[i];
                temp.push_back(v[i]);
                solve(v,k,target,temp,sum,i+1);
                sum-=v[i];
                temp.pop_back();
            }
            i++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        for(int i = 1; i<=9; i++) v.push_back(i);
        vector<int> temp;
        int sum = 0;
        solve(v,k,n,temp,sum,0);
        return ans;
    }
};