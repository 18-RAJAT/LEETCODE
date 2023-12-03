class Solution {
public:
    int path(vector<int>& a,vector<int>& b)
    {
        return max(abs(a[0]-b[0]),abs(a[1]-b[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();++i)
        {
            ans+=path(points[i],points[i-1]);
        }
        return ans;
    }
};