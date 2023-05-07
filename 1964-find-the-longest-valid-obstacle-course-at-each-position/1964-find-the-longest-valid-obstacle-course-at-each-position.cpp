class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n);
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        int len=0;
        for(int i=0;i<n;++i)
        {
            int idx=upper_bound(dp.begin(),dp.end(),obstacles[i])-dp.begin();
            dp[idx]=obstacles[i];
            len=max(len,idx);
            ans[i]=idx;
        }
        return ans;
    }
};