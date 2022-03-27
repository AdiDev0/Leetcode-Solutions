class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> m1, m2;
        set<int> s1,s2;
        
        vector<int> ans1, ans2;
        
        for(int i = 0; i<n; i++){
            m1[nums1[i]]++;
        }
        for(int i = 0; i<m; i++){
            m2[nums2[i]]++;
        }

        for(int i = 0; i<n; i++){
            if(!m2[nums1[i]] and s1.find(nums1[i])==s1.end()){
                ans1.push_back(nums1[i]);
                s1.insert(nums1[i]);
            }
        }
        
        for(int i = 0; i<m; i++){
            if(!m1[nums2[i]] and s2.find(nums2[i])==s2.end()){
                ans2.push_back(nums2[i]);
                s2.insert(nums2[i]);
            }
        }
        
        vector<vector<int>> v;
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};