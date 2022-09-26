class Solution {
public:
    int getParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = getParent(parent, parent[node]);
    }
    bool equationsPossible(vector<string>& e) {
        int n = e.size();
        vector<int> parent(26, 0);
        vector<int> rank(26,0);
        for(int i = 0; i<26; i++){
            parent[i] = i;
        }
        for(int i = 0; i<n; i++){
            int u = e[i][0]-'a';
            int v = e[i][3]-'a';
            
            int pu = getParent(parent, u);
            int pv = getParent(parent, v);
            
            if(e[i][1]=='='){
                if(rank[pu]<rank[pv]){
                    parent[pu] = pv;
                }
                else if(rank[pu]>rank[pv]){
                    parent[pv] = pu;
                }
                else{
                    parent[pv] = pu;
                    rank[pu]++;
                }
            }
        }
        for(int i = 0; i<n; i++){
            int u = e[i][0]-'a';
            int v = e[i][3]-'a';
            
            int pu = getParent(parent, u);
            int pv = getParent(parent, v);
            
            if(e[i][1]=='!'){
                if(parent[pu]==parent[pv]){
                    return false;
                }
            }
        }
        return true;
    }
};

// arr = ["b==a","b==c","x==y","y==z","k==k"]
// on the basis of equality 3 sets will be made.
// 1 -> a, b, c (all of them are equal to one another, we will use 'a' as the representative of this set);
// 2 -> x,y,z  (we will use 'x' as the representative of this set)
// 3 -> k  (we will use 'k' as the representative of this set)


// Disjoint set union

// 1. It basically divides the elements into multiple sets.
// 2. No element can belong to multiple sets.
// 3. Each set has an element which is their representative ...it is also known as Parent.
// 4. The rank representes the size of the set.
// 5. We can combine/union two sets or one set and a element into a single set.
// 6. The set will smaller rank combines to the set with greater rank.





