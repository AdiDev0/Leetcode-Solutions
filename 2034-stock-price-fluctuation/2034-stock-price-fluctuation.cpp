class StockPrice {
public:
    map<int,int> m, p;
    int curr = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(m[timestamp]>0){
            int prevPrice = m[timestamp];
            if(p[prevPrice]==1){
                p.erase(prevPrice);
            }
            else{
                p[prevPrice]--;
            }
        }
        p[price]++;
        m[timestamp] = price;
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return p.rbegin()->first;
    }
    
    int minimum() {
        return p.begin()->first;
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