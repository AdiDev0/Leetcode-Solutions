class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        if(digits[n-1]==9){
            int i = n-1;
            int carry = 1;
            while(i>=0 and digits[i]==9){
                digits[i] = 0;
                i--;
            }
            if(i>=0){
                digits[i]++;
            }
            else{
                ans.push_back(1);
            }
        }
        else{
            digits[n-1]++;
        }
        for(int i = 0; i<n; i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};