class Solution {
public:
    int leastInterval(vector<char>& task, int sp) {
        int n = task.size();
        unordered_map<char,int> m;
        priority_queue<int> pq;
        long long day = 0;
        for(int i = 0; i<n; i++){
            if(m.find(task[i])==m.end()){
                m[task[i]] = 0;
                pq.push(0);
            }
            else{
                m[task[i]] += sp+1;
                pq.push(-1*m[task[i]]);
            }
        }
        
        while(!pq.empty()){
            int t = -1*pq.top();
            pq.pop();
            if(t>day){
                pq.push(-1*t);
            }
            day++;
        }
        return day;
    }
};