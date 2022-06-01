bool compare(vector<int>&a,vector<int>&b)
{
        return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
            int answer=0;
            int arrow=0;
            
            for(int i=0;i<points.size();++i)
            {
                    if(answer==0 or points[i][0]>arrow)
                    {
                            answer++;
                            arrow=points[i][1];
                    }
            }
            return answer;
    }
};
