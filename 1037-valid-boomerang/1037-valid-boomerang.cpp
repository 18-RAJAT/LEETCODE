class Solution {
public:
    bool isBoomerang(vector<vector<int>>&p) {
        vector<int>a,b,c;
        a=p[0];b=p[1];c=p[2];
        return ((a[0]-b[0])*(b[1]-c[1]))!=((b[0]-c[0])*(a[1]-b[1]));
    }
};