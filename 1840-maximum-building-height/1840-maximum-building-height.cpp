class Solution{
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.empty())return n-1;
        sort(restrictions.begin(),restrictions.end());
        int idx=1,h=0;
        for(int i=0;i<restrictions.size();++i)
        {
            int x=restrictions[i][0],y=restrictions[i][1];
            restrictions[i][1]=min(y,x-idx+h);
            idx=x,h=restrictions[i][1];
        }
        for(int i=restrictions.size()-2;~i;--i)
        {
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+restrictions[i+1][0]-restrictions[i][0]);
        }
        int ans=n-restrictions.back()[0]+restrictions.back()[1];
        idx=1,h=0;
        for(auto& it:restrictions)
        {
            int x=it[0],y=it[1];
            int steps=x-idx-abs(y-h);
            int mx=max(y,h);
            ans=max(ans,mx+steps/2);
            idx=x;
            h=y;
        }
        return ans;
    }
};