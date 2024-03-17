class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0])//for non-overlapping intervals
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size() && intervals[i][0]<=newInterval[1])//for overlapping intervals
        {
            newInterval[0]=min(newInterval[0],intervals[i][0]);//updating the start point of newInterval
            newInterval[1]=max(newInterval[1],intervals[i][1]);//updating the end point of newInterval
            i++;
        }
        ans.push_back(newInterval);
        while(i<intervals.size())//for non-overlapping intervals
        {
            ans.push_back(intervals[i]);//pushing the remaining intervals
            i++;
        }
        return ans;
    }
};