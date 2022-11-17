class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ans=(ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-max(min(ay2,by2)-max(by1,ay1),0)*max(min(ax2,bx2)-max(bx1,ax1),0);
        return ans;
    }
};