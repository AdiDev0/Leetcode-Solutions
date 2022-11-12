class MedianFinder {
public:
    
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max.empty()){
            max.push(num);
        }
        else if(max.size() > min.size()){
            if(num<max.top()){
                max.push(num);
                min.push(max.top());
                max.pop();
            }
            else{
                min.push(num);
            }
        }
        else if(min.size()==max.size()){
            if(num>min.top()){
                min.push(num);
                max.push(min.top());
                min.pop();
            }
            else{
                max.push(num);
            }
        }
    }
    
    double findMedian() {
        if(min.size()==max.size()){
            return (double)(max.top() + min.top())/2.0;
        }
        return double(max.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */