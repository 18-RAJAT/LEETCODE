class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size(),m=waterStartTime.size();
        vector<vector<int>>a(n,vector<int>(2,0)),b(m,vector<int>(2,0));
        for(int i=0;i<n;++i)
        {
            a[i][0]=landStartTime[i]+landDuration[i];
            a[i][1]=landStartTime[i];
        }
        for(int i=0;i<m;++i)
        {
            b[i][0]=waterStartTime[i]+waterDuration[i];
            b[i][1]=waterStartTime[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=INT_MAX,cur=a[0][0];

        for(int i=0;i<m;++i)ans=min(ans,waterDuration[i]+max(waterStartTime[i],cur));
        int tmp=b[0][0];
        for(int i=0;i<n;++i)ans=min(ans,landDuration[i]+max(landStartTime[i],tmp));
        return ans;
    }
};