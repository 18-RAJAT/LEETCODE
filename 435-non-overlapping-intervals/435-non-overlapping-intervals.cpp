bool compare(vector<int>& a,vector<int>& b)
{
        return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
           
            int answer=0;
            int currentEnd=intervals[0][1];
            for(int i=1;i<intervals.size();++i)
            {
                    if(intervals[i][0] >= currentEnd)
                    {
                            currentEnd=intervals[i][1];
                    }
                   else{answer++;}
            }
            return answer;
    }
};