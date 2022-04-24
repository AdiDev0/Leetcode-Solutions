class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> m;
    unordered_map<string, vector<int>> mpp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto temp = m[id];
        string name = temp.first;
        name.push_back('$');
        name.append(stationName);
        int timeDiff = t-temp.second;
        mpp[name].push_back(timeDiff);
        m.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int sum = 0;
        string name = startStation;
        name.push_back('$');
        name.append(endStation);
        vector<int> v = mpp[name];
        for(int i = 0; i<v.size(); i++){
            sum+=v[i];
        }
        double ans = (double)sum/v.size();
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */