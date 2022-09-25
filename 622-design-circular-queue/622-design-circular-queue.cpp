class MyCircularQueue {
public:
    vector<int> v;
    int f = 0;
    int r = -1;
    int k = 0;
    int cnt = 0;
    MyCircularQueue(int K) {
        v.resize(K, -1);
        k = K;
    }
    
    bool enQueue(int value) {
        if(v[(r+1)%k]==-1){
            v[(r+1)%k] = value;
            r = (r+1)%k;
            cnt++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(v[f]!=-1){
            v[f] = -1;
            f = (f+1)%k;
            cnt--;
            return true;
        }
        return false;
    }
    
    int Front() {
        return v[f];
    }
    
    int Rear() {
        return r>=0?v[r]:-1;
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */