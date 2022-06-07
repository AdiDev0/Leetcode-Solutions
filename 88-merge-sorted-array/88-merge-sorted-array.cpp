class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size()-1;
        int i = nums2.size()-1;
        int j = m-1;
        while(j>=0 and i>=0){
            if(nums2[i]>nums1[j]){
                nums1[k] = nums2[i];
                k--;
                i--;
            }
            else if(nums2[i]<nums1[j]){
                nums1[k] = nums1[j];
                k--;
                j--;
            }
            else{
                nums1[k] = nums1[j];
                k--;
                j--;
                nums1[k] = nums2[i];
                k--;
                i--;
            }
        }
        while(i>=0){
            nums1[k] = nums2[i];
            k--;
            i--;
        }
    }
};