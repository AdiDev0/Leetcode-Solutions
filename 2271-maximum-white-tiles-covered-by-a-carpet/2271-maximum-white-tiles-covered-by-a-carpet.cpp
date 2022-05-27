class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        
        int areaCov = 0;
        int currAns = 0;
        int ans = 0;
        int j = 0;
        int i = 0;
        while(i<n and j<n){
            if(tiles[i][0]+carpetLen>tiles[j][1]){
                areaCov += tiles[j][1]-tiles[j][0]+1;
                ans = max(ans, areaCov);
                j++;
            }
            else{
                ans = max(ans,areaCov+max(0,tiles[i][0]+carpetLen-tiles[j][0]));
                areaCov -= tiles[i][1]-tiles[i][0]+1;
                i++;
            }
        }
        return ans;
    }
};