class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        if(r2[1]>=r1[3] or r1[0]>=r2[2] or r1[1]>=r2[3] or r2[0]>=r1[2]){return false;}
        return true;
    }
};