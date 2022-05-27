class Solution {
public:
    int numberOfSteps(int nums) {
        int steps = 0;
        while(nums>0){
            if(nums%2==0) nums/=2;
            else nums-=1;
            steps++;
        }
        return steps;
    }
};