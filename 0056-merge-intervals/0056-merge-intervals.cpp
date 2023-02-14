class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        while(i<n)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            
            while(i<n-1 and intervals[i+1][0]<=end)
            {
                end=max(intervals[i+1][1],end);
                i++;
            }
            ans.push_back({start,end});
            i++;
        }
        return ans;
    }
};