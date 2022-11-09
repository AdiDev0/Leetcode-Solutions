class StockSpanner {
public:
    stack<int> st;
    unordered_map<int, int> map;
    
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        if(st.empty())
        {
            st.push(price);
            map[price] = 1; 
            return map[price]; 
        }
        
        int span = 0;
        
        while(!st.empty() && price >= st.top())
        {
            span = span + map[st.top()];
            st.pop();
        }
        
        st.push(price);
        map[price] = span+1; 
        return map[price]; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */