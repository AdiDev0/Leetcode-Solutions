class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
         // return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
        if(a[1]<b[1]) return true;
        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);
        // for(int i = 0; i<n; i++){
        //     cout<<events[i][0]<<" "<<events[i][1]<<endl;
        // }
        int count = 0;
        vector<int> vis(100001, 0);
        unordered_map<int,int> m;
        int lastFound = 0;
        for(int i = 0; i<n; i++){
            int end = events[i][1];
            int start = (i>0 and events[i-1][0]==events[i][0]) ? lastFound: events[i][0];
            while(start<=end){
                if(vis[start]==0){
                    vis[start] = 1;
                    lastFound = start;
                    count++;
                    break;
                }
                start++;
            }
        }
        return count;
    }
};