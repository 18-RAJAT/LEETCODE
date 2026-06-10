class Solution {
public:
    int ar[16][50010],br[16][50010];
    int value(int l,int r)
    {
        int k=31-__builtin_clz(r-l+1);
        int mn=min(ar[k][l],ar[k][r-(1<<k)+1]),mx=max(br[k][l],br[k][r-(1<<k)+1]);
        return mx-mn;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;++i)ar[0][i]=br[0][i]=nums[i];
        for(int i=1;i<16;++i)
        {
            for(int j=0;j+(1<<i)-1<n;++j)
            {
                ar[i][j]=min(ar[i-1][j],ar[i-1][j+(1<<(i-1))]);
                br[i][j]=max(br[i-1][j],br[i-1][j+(1<<(i-1))]);
            }
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({value(0,n-1),{0,n-1}});
        set<pair<int,int>>vis;
        vis.insert({0,n-1});
        long long sum=0;
        while(k>=1)
        {
            sum+=pq.top().first;
            int l=pq.top().second.first,r=pq.top().second.second;
            pq.pop();
            if(l<r)
            {
                if(!vis.count({l,r-1}))
                {
                    vis.insert({l,r-1});
                    pq.push({value(l,r-1),{l,r-1}});
                }
                if(!vis.count({l+1,r}))
                {
                    vis.insert({l+1,r});
                    pq.push({value(l+1,r),{l+1,r}});
                }
            }
            k--;
        }
        return sum;
    }
};