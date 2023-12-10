class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cnt=0;
        int n=batteryPercentages.size();
        for(int i=0;i<n;++i)
        {
            if((batteryPercentages[i]-cnt)>=1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};