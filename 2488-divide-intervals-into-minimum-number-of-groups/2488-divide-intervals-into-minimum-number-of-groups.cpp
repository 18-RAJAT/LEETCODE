class Solution{
public:
    int minGroups(vector<vector<int>>&intervals){
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans=0;
        for(auto&interval:intervals)
        {
            int start=interval[0],end=interval[1];
            if(pq.empty() || pq.top()>start)ans++;
            else pq.pop();
            pq.push(end+1);
        }
        return ans;
    }
};