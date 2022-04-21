class MyHashSet {
    vector<set<int>> v;
    int size = 769;
public:
    MyHashSet(){
        v.resize(size);
    }
    int hash(int i){
        return i%size;
    }
    void add(int key) {
        int index = hash(key);
        v[index].insert(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        v[index].erase(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        return v[index].find(key)!=v[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */