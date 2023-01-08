class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2)
        {
            return n;
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int point1=points[i][0];
            int point2=points[i][1];
            int same=1,vertical=0,maxPoint=0;
            map<double,int>mp;
            for(int j=i+1;j<n;++j)
            {
                int pts1=points[j][0];
                int pts2=points[j][1];
                
                if(point1==pts1 and point2==pts2)
                {
                    same++;
                }
                else if(point1==pts1)
                {
                    vertical++;
                }
                else
                {
                    double slope=(double)(pts2-point2)/(pts1-point1);
                    mp[slope]++;
                    maxPoint=max(maxPoint,mp[slope]);
                }
            }
            maxPoint=max(maxPoint,vertical);
            int isSame=maxPoint+same;
            ans=max(ans,isSame);
        }
        return ans;     
    }
};