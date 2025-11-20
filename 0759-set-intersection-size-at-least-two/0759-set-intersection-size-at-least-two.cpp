class Solution{
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b)
        {
            return a[1]<b[1];
        });
        int x=-1,y=-1,ans=0;
        for(int i=0;i<n;++i)
        {
            int l=intervals[i][0],r=intervals[i][1];
            if(x>=l && y>=l && x<=r && y<=r)continue;
            else if(y>=l && y<=r)
            {
                x=y,y=r;
                if(x==y)x--;
                ans++;
            }
            else
            {
                x=r-1,y=r;
                ans+=2;
            }
        }
        return ans;
    }
};