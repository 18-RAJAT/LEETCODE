class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2)return n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int same=1;
            int vertical=0;
            int maxPoints=0;
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                {
                    same++;
                }
                else if(points[i][0]==points[j][0])
                {
                    vertical++;
                }
                else
                {
                    double slope=(double)(points[i][1]-points[j][1])/(points[i][0]-points[j][0]);
                    mp[slope]++;
                    maxPoints=max(maxPoints,mp[slope]);
                }
            }
            maxPoints=max(maxPoints,vertical);
            ans=max(ans,maxPoints+same);
        }
        return ans;      
    }
};