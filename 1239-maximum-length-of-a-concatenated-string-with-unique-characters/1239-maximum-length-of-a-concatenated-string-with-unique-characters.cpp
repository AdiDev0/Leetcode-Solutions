class Solution {
public:
    // int checkUnique(string &s){
    //     int n = s.size();
    //     unordered_map<char,int> m;
    //     for(int i = 0; i<n; i++){
    //         if(m[s[i]]){
    //             return -1;
    //         }
    //         m[s[i]]++;
    //     }
    //     return n;
    // }
    // or
    int checkUnique(string &s){
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++)
            if(count[s[i] - 'a']++ > 0) return -1;
        
        return s.size();
    }
    void solve(vector<string> &arr , string temp, int index, int &ans){
        string prev = temp;
        int i = index;
        while(i<arr.size()){
            string curr = prev+arr[i];
            int lenght = checkUnique(curr);
            if(lenght>0){
                ans = max(ans,lenght);
                solve(arr,curr,i+1, ans);
            }
            i++;
        }
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;
        solve(arr, "", 0, ans);
        return ans;
    }
};