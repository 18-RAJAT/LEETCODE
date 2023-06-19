class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude=0,maxi=0;
        for(int i=0;i<gain.size();++i)
        {
            altitude+=gain[i];
            if(maxi<altitude)
            {
                maxi=altitude;
            }
        }
        return maxi;
    }
};