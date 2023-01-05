bool cmp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans=0,arrow=0;
        int n=points.size();
        for(int i=0;i<n;++i)
        {
            if(arrow<points[i][0] or ans==0)
            {
                ans++;
                arrow=points[i][1];
            }
        }
        return ans;
    }
};
