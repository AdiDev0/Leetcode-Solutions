/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    void flatten(vector<NestedInteger> &nestedList){
        int n = nestedList.size();
        for(auto &it:nestedList){
            if(it.isInteger()){
                v.push_back(it.getInteger());
            }
            else{
                flatten(it.getList());
            }
        }
    }
public:
    vector<int> v;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    int i = 0;
    int next(){
        return v[i++];
    }
    
    bool hasNext() {
        return i<v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */