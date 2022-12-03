class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto i: s) {
            m[i]++;
        }
        vector<pair<int, char>> v;
        for(auto i: m) {
            v.push_back({i.second, i.first});
        }
        // sort(v.begin(), v.end(), [&](pair<char, int> a, pair<char, int> b) -> bool {
        //    if(a.second == b.second) {
        //        return a.first < b.second;
        //    } 
        //    return a.second > b.second;
        // });
        // sort by decending order.
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string x;
        for(auto i: v) {
            for(int j=0;j<i.first;j++) {
                x += i.second;   
            }
        }
        return x;
    }
};
