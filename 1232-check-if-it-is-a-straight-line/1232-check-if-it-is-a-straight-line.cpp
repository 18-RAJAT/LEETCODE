class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        double x0=coordinates[0][0],y0=coordinates[0][1];
        double x1=coordinates[1][0],y1=coordinates[1][1];
        bool isVertical=(x1==x0);
        double slope;
        if(not isVertical)
        {
            slope=(y1-y0)/(x1-x0);
        }

        for(int i=2;i<n;++i)
        {
            double x=coordinates[i][0],y=coordinates[i][1];
            if(isVertical)
            {
                if(x!=x0)
                {
                     return 0;
                }
                continue;
            } 
            else if((y-y0)!=(x-x0)*slope)
            {
                return 0;
            }
        }
        return 1;
    }
};