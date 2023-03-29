class Solution {
public:
        int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(),satisfaction.rend());
        int n=satisfaction.size();
        vector<int>sum;
        sum=satisfaction;
        for(int i=1;i<n;++i)
        {
            sum[i]+=sum[i-1];
        }
        int mx=0,cs=0;
        for(int i=0;i<n;++i)
        {
            cs+=sum[i];
            mx=max(cs,mx);
        }
        return mx;
    }
};