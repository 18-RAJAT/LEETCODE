class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        auto dist=[&](int sx,int sy,int fx,int fy)->int
        {
            return max(abs(sx-fx),abs(sy-fy));
        };
        int distance=dist(sx,sy,fx,fy);
        // if(distance==0)
        // {
        //     return t==0?true:false;
        // }
        if(distance>0)
        {
            return t>=distance?true:false;
        }
        return t!=1?true:false;
    }
};