class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size(),m=waterStartTime.size();
        int land=1e9,water=1e9,lw=1e9,wl=1e9;
        for(int i=0;i<n;++i)
        {
            land=min(land,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;++i)
        {
            water=min(water,waterStartTime[i]+waterDuration[i]);
            lw=min(lw,max(waterStartTime[i],land)+waterDuration[i]);
        }
        for(int i=0;i<n;++i)
        {
            wl=min(wl,max(landStartTime[i],water)+landDuration[i]);
        }
        return min(wl,lw);
    }
};