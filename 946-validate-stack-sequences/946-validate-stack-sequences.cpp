class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        int n = pu.size();
        int i = 0;
        int j = 0;
        stack<int> s;
        while(i<n){
            if(!s.empty() and s.top()==po[j]){
                s.pop();
                j++;
            }
            else if(i<n){
                s.push(pu[i]);
                i++;
            }
            else{
                return false;
            }
        }
        while(j<n and s.top()==po[j]){
            s.pop();
            j++;
        }
        if(s.size()>0) return false;
        return true;
    }
};