class Solution {
public:
    void merge(vector<int> &nums,int low,int mid,int high){
        int i = low;
        int j = mid+1;
        int k = 0;
        vector<int> temp(high-low+1, 0);
        
        while(i<=mid and j<=high){
            if(nums[i]<nums[j]){
                temp[k++] = nums[i++];
            }
            else if(nums[i]>nums[j]){
                temp[k++] = nums[j++];
            }
            else{
                temp[k++] = nums[i++];
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        while(j<=high){
            temp[k++] = nums[j++];
        }
        
        for(int i = low; i<=high; i++){
            nums[i] = temp[i-low];
        }
        
    }
    void mergeSort(int low , int high ,vector<int> &nums){
        if(low<high){
            int mid = low + (high-low)/2;
            mergeSort(low , mid ,nums);
            mergeSort(mid+1, high,nums);
            merge(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        mergeSort(l,h,nums);
        return nums;
    }
};