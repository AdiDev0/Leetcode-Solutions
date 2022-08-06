class Solution {
public:
    long long taskSchedulerII(vector<int>& task, int sp){
        unordered_map<long long, long long> m;
        int n = task.size();
        long long day = 0;
        for(int i = 0; i<n; i++){
            if(m.find(task[i])==m.end()){
                m[task[i]] = day+sp+1;
            }
            else{
                day = max(day, m[task[i]]);
                m[task[i]] = day+sp+1;
            }     
            day++;
        }
        return day;
    }
};