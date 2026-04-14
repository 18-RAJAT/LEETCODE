class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> res;
        for(auto& it:factory)
        {
            for(int i=0;i<it[1];++i)
            {
                res.push_back(it[0]);
            }
        }
        int rc=robot.size(),fc=res.size();
        vector<vector<long long int>>dp(rc+1,vector<long long int>(fc+1,0));
        for(int i=0;i<rc;++i)
        {
            dp[i][fc]=1e12;
        }
        for(int i=rc-1;~i;--i)
        {
            for(int j=fc-1;~j;--j)
            {
                long long int take=abs(robot[i]-res[j])+dp[i+1][j+1];
                long long int leave=dp[i][j+1];
                dp[i][j]=min(take,leave);
            }
        }
        return dp[0][0];
    }
};