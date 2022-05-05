class MyStack {
public:
    queue<int> a,b;
    MyStack() {
        
    }
    
    void push(int x) {
        b.push(x);
        while(!a.empty()){
            b.push(a.front());
            a.pop();
        }
        swap(a,b);
    }
    
    int pop() {
        int temp = a.front();
        a.pop();
        return temp;
    }
    
    int top() {
        return a.front();
    }
    
    bool empty() {
        return !a.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */