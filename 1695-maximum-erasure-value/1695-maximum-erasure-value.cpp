class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(),i=0,j=0,ans=INT_MIN,sum=0,cnt=0;
        unordered_map<int,int> m;
        while(j<n){
            sum+=nums[j];
            cnt++;
            m[nums[j]]++;
            while(m.size()!=cnt){
                sum-=nums[i];
                cnt--;
                if(m[nums[i]]>1) m[nums[i]]--;
                else m.erase(nums[i]);
                i++;
            }
            ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};