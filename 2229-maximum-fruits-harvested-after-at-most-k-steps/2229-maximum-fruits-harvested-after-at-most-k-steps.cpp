class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size(),j=0,sum=0,ans=0;
        for(int i=0;i<n;++i)
        {
            sum+=fruits[i][1];
            while(j<=i)
            {
                int x=fruits[j][0],y=fruits[i][0];
                int dist=min(abs(startPos-x)+(y-x),abs(startPos-y)+(y-x));
                if(dist<=k)break;
                sum-=fruits[j][1];
                j++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};