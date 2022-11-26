class Solution {
public:
 
    int latest_non_overlap_opt(vector<vector<int>> &job,int i)
    {
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (job[mid][0] <= job[i][1])  
            {
                if (job[mid + 1][0] <= job[i][1]) 
                    low = mid + 1;
                else                
                    return mid;
            }
            else
                high = mid - 1;
        }
        return -1;
    }



    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>>job(n,vector<int>(3));

        for(int i=0;i<n;i++)
        {
            job[i] = {endTime[i],startTime[i],profit[i]};
        }


        sort(job.begin(),job.end());


        vector<int> dp(n,0);
        dp[0] = job[0][2];


        for(int i=1;i<n;i++)
        {

            int exclusive = dp[i-1];
            int inclusive = job[i][2];
            int index = latest_non_overlap_opt(job,i);
           
            if(index!=-1)
                inclusive += dp[index]; 
            dp[i] = max(inclusive,exclusive);
        }
        return dp[n-1];
    }
};