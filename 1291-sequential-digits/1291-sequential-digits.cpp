class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string a = to_string(low);
        string b = to_string(high);
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        for(int i = n; i<=m; i++){
            long long val = 1;
            int l = i-1;
            while(l--){
                val*=10;
            }
            long long num = 0;
            for(int k = 1; k<=i; k++){
                num = num*10+k;
            }
            if(num%10==9 and num>=low and num<=high){
                ans.push_back(num);
                break;
            }
            while(num%10!=9){
                if(num>=low and num<=high){
                    ans.push_back(num);
                }
                num = num%val;
                long long lastDig = num%10;
                num = num*10+(lastDig+1);
            }
            if(num>=low and num<=high){
                ans.push_back(num);
            }
        }
        return ans;
    }
};