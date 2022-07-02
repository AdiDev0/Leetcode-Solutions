class Solution {
public:
    int maxArea(int n, int m, vector<int> &h, vector<int> &v) {
        v.push_back(m);
        h.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        long ans = 0;
        int mod = 1e9+7;
        
        int hGap = 0;
        int vGap = 0;
        
        for(int i = 0; i<v.size(); i++){
            if(i==0){
                vGap = max(vGap, v[i]);
            }
            else{
                vGap = max(vGap, v[i]-v[i-1]);
            }
        }
        for(int i = 0; i<h.size(); i++){
            if(i==0){
                hGap = max(hGap, h[i]);
            }
            else{
                hGap = max(hGap, h[i]-h[i-1]);
            }
        }
        return ans = (long)hGap*vGap%mod;
    }
};