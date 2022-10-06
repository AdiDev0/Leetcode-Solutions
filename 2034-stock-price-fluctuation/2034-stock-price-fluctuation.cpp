class StockPrice {
public:
    map<int,int> m;
    multiset<int> s;
    int curr = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(m[timestamp]>0){
            int prevPrice = m[timestamp];
            s.erase(s.find(prevPrice));
        }
        s.insert(price);
        m[timestamp] = price;
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        auto it = s.end();
        it--;
        return *it;
    }
    
    int minimum() {
        auto it = s.begin();
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */