class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0,temp=values[0];
        for(int j=1;j<values.size();++j)
        {
            ans=max(ans,temp+values[j]-j);
            temp=max(temp,values[j]+j);
        }
        return ans;
    }
};