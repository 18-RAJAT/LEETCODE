class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](auto& a,auto& b)
        {
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=points.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            int res=INT_MIN;
            for(int j=i+1;j<n;++j)
            {
                if(points[j][1]<=points[i][1] && res<points[j][1])
                {
                    ans++,res=points[j][1];
                }
            }
        }
        return ans;
    }
};