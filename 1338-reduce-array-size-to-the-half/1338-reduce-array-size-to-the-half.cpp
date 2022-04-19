class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(auto it: arr){
            m[it]++;
        }
        vector<int> v;
        for(auto it: m){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int i = v.size()-1;
        while(i>=0){
            sum+=v[i];
            if(sum>=n/2){
                return v.size()-i;
            }
            i--;
        }
        return n;
    }
};