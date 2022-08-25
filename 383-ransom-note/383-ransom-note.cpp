class Solution {
public:
    bool canConstruct(string ra, string ma) {
        int n = ra.size();
        unordered_map<char,int> mpp;
        for(auto it: ma){
            mpp[it]++;
        }
        for(auto it: ra){
            if(mpp[it]>0) mpp[it]--;
            else return false;
        }
        return true;
    }
};