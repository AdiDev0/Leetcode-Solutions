class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        auto ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> ans;
        int count = 0;
        int i = ind-1;
        int j = ind;
        
        while(count<k){
            if(i<0 and j<n){
                ans.push_back(arr[j++]);
                count++;
            }
            if(j>=n and i>=0){
                ans.push_back(arr[i--]);
                count++;
            }
            if(i>=0 and j<n){
                if(abs(arr[i]-x)<=abs(arr[j]-x)){
                    ans.push_back(arr[i--]);
                    count++;
                }
                else{
                    ans.push_back(arr[j++]);
                    count++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};