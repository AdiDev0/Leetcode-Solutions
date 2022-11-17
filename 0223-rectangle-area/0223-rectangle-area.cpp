class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int area1 = abs(ax2-ax1)*abs(ay2-ay1);
        int area2 = abs(bx2-bx1)*abs(by2-by1);
        // cout<<area1<<" "<<area2;
        if(bx1>=ax2 or ay1>=by2 or by1>=ay2 or bx2<=ax1){
            return area1+area2;
        }
        
        return area1+area2-(abs(min(ax2, bx2) - max(ax1, bx1))*abs(min(ay2, by2) - max(ay1, by1)));
    }
};                                                                                                                                                                                                                       