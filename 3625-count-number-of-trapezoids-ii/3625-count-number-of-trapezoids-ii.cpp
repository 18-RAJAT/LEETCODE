class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<double,unordered_map<double,int>>mp1;
        unordered_map<int,unordered_map<double,int>>mp2;
        mp1.reserve(n*n);
        mp2.reserve(n*n);
        for(int i=0;i<n;++i)
        {
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<i;++j)
            {
                int x2=points[j][0],y2=points[j][1];
                int dx=x2-x1,dy=y2-y1;
                double p1=(dx==0?1e9:1.0*dy/dx);
                double p2=(dx==0?x1:1.0*(1LL*y1*dx-1LL*x1*dy)/dx);
                mp1[p1][p2]++;
                int p=((x1+x2+2005)<<12)+(y1+y2+2005);
                mp2[p][p1]++;
            }
        }
        int ans=0;
        for(auto& [it,it1]:mp1)
        {
            int s=0;
            for(auto& [it,t]:it1)
            {
                ans+=s*t;
                s+=t;
            }
        }
        for(auto& [it,it1]:mp2)
        {
            int s=0;
            for(auto& [it,t]:it1)
            {
                ans-=s*t;
                s+=t;
            }
        }
        return ans;
    }
};