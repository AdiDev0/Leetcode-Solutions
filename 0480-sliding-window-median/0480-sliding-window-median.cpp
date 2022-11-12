class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<long long> s;
        vector<double> ans;
        int i = 0;
        int j = 0;
        while(j<n){
            s.insert(nums[j]);
            if(j>=k-1){
                if(k%2==0){
                    auto it1 = next(s.begin(), k/2);
                    auto it2 = next(s.begin(), (k/2)-1);
                    long long v = *it1 + *it2;
                    ans.push_back((double)v/2);
                }
                else{
                    auto it = next(s.begin(), k/2);
                    ans.push_back((double)*it);
                }
                s.erase(s.find(nums[i]));
                i++;
            }
            j++;
        }
        return ans;
    }
};

// 1  1  3  4  5  7  8  8