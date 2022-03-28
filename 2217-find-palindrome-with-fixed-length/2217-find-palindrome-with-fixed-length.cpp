class Solution {
public:
    long long findNthPalindrome(int Nth, int start, int len){
        long long int Nth_no = start+Nth-1;
        long long int temp = Nth_no;
        if(len%2!=0){
            temp = temp/10;
        }
        while(temp>0){
            int lastDigit = temp%10;
            Nth_no = (unsigned long)Nth_no*10+lastDigit;
            temp = temp/10;
        }
        if(Nth_no >= pow(10,len) or Nth_no <= -1*pow(10,len)){
            return -1;
        }
        return Nth_no;
    }
    vector<long long> kthPalindrome(vector<int>& q, int len) {
        int n = q.size();
        int k = 0;
        if(len%2==0) k = len/2 - 1;
        else k = len/2;
        
        long long int start = pow(10, k);
        vector<long long> ans;
        for(int i = 0; i<n; i++){
            long long int currAns = findNthPalindrome(q[i], start, len);
            ans.push_back(currAns);
        }
        return ans;
    }
};