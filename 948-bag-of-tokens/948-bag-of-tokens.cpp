class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power){
        int n = t.size();
        int score = 0;
        sort(t.begin(), t.end());
        
        int i = 0, j = n-1;
        
        while(i<=j){
            if(power>=t[i]){
                power-=t[i++];
                score++;
            }
            else if(score>0 and i!=j){
                power+=t[j--];
                score--;
            }
            else{
                break;
            }
        }
        return score;
    }
};