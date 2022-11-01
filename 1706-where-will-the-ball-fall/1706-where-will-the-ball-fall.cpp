class node{
public:
    int xx;
    int yy;
    char l;
    int loc;
    node(int a, int b, char c, int d){
        xx = a;
        yy = b;
        l = c;
        loc = d;
    }
};

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<node> q;
        vector<int> ans(m, -1);
        for(int i = 0; i<m; i++){
            node *n = new node(0, i, 'd', i);
            q.push(*n);
        }
        // node *nn = new node(0, 4, 'd', 4);
        // q.push(*nn);
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.xx;
            int y = t.yy;
            // cout<<x<<" "<<y<<endl;
            if(x==n){
                ans[t.loc] = y;
                continue;
            }
            if(t.l == 'd'){
                if(grid[x][y]==1){
                    if(y+1<m and grid[x][y+1]==1){
                        node *n = new node(x, y+1, 'r', t.loc);
                        q.push(*n);
                    }
                }
                else{
                    if(y-1>=0 and grid[x][y-1]==-1){
                        node *n = new node(x, y-1, 'l', t.loc);
                        q.push(*n);
                    }
                }
            }
            else{
                node *n = new node(x+1, y, 'd', t.loc);
                q.push(*n);
            }
        }
        return ans;
    }
};