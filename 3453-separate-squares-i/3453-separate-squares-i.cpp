class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        deque<array<long long,2>>dq;
        for(auto& it:squares)dq.push_back({it[1],it[2]});
        long double res=0.0L;
        for(auto& it:dq)res+=it[1]*it[1];
        long double ele=res/2.0L,l=0.0L,r=0.0L;
        for(auto& it:dq)r=max(r,(long double)(it[0]+it[1]));
        auto recur=[&](long double k)->long double
        {
            long double ans=0.0L;
            for(auto& it:dq)
            {
                long double y=it[0],l=it[1],top=y+l;
                if(k<=y)ans+=l*l;
                else if(k<top)ans+=l*(top-k);
            }
            return ans;
        };
        for(int i=0;i<100;++i)
        {
            long double mid=(l+r)/2.0L,val=recur(mid);
            (ele<val)?l=mid:r=mid;
        }
        return (double)r;
    }
};