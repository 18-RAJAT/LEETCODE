class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n=profit.size();
        
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++)
        {
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        
        vector<int> dp;
        dp.push_back(jobs[0][2]);
        
        for(int i=1;i<n;i++)
        {
            int including = jobs[i][2];
            int lastoverlapping = -1;
            
            for(int j=i-1;j>=0;j--)
            {
                if(jobs[j][0]<=jobs[i][1])
                {
                    lastoverlapping = j;
                    break;
                }
            }
            if(lastoverlapping != -1)
                including += dp[lastoverlapping];
            
            dp.push_back( max(dp[i-1],including) );
        }
        
        return dp[n-1];
    }
};