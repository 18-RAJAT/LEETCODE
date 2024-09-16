class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int minDiff=INT_MAX;
        sort(timePoints.begin(),timePoints.end());
        for(int i=0;i<timePoints.size();i++){
            int h1=stoi(timePoints[i].substr(0,2)),m1=stoi(timePoints[i].substr(3,2));
            int h2=stoi(timePoints[(i+1)%timePoints.size()].substr(0,2)),m2=stoi(timePoints[(i+1)%timePoints.size()].substr(3,2));
            int diff=(h2-h1)*60+(m2-m1);
            if(diff<0)diff+=1440;
            minDiff=min(minDiff,diff);
        }
        return minDiff;
    }
};