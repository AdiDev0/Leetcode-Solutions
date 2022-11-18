class Solution {
public:
    bool isUgly(int n) {
        if(n==0){
            return 0;
        }
        while(n!=1){
            if(n%2==0){
                n = n/2;
                continue;
            }
            if(n%3==0){
                n = n/3;
                continue;
            }
            if(n%5==0){
                n = n/5;
                continue;
            }
            break;
        }
        if(n==1){
            return true;
        }
        return false;
    }
};