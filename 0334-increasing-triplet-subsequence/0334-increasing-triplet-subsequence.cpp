class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n = arr.size();
        int smallestNo = INT_MAX;
        int secondSmallestNo = INT_MAX;
        for(int i = 0; i<n; i++){
            if(arr[i]<smallestNo){
                smallestNo = arr[i];
            }
            else if(arr[i]>smallestNo and arr[i]<secondSmallestNo){
                secondSmallestNo = arr[i];
            }
            else if(arr[i]>secondSmallestNo){
                return true;
            }
        }
        return false;
    }
};