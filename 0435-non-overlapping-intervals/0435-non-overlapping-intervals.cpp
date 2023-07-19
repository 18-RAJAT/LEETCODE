class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=0,last=0;
        for (int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0]>=intervals[last][1])
            {
                last=i;
            }
            else
            {
                res++;
                last=intervals[last][1]>intervals[i][1]?i:last; 
            }
        }
        return res;
    }
};