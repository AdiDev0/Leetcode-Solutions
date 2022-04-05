class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int l = 0;
        int h = n-1;
        while(l<h){
            if(height[l]>height[h]){
                maxWater = max(maxWater , height[h]*(h-l));
                h--;
            }
            else{
                maxWater = max(maxWater , height[l]*(h-l));
                l++;
            }
        }
        return maxWater;
    }
};