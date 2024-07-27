class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=source.size();
        int m=target.size();
        if(n!=m)
        {
            return -1;
        }
        vector<vector<long long>>dijkstra(26,vector<long long>(26,1e15));
        dijkstra[0][0]=0;
        for(int i=0;i<26;++i)
        {
            dijkstra[i][i]=0;
        }
        auto convert=[](char c)->int
        {
            return c-'a';
        };
        for(int i=0;i<original.size();++i)
        {
            dijkstra[convert(original[i])][convert(changed[i])]=min(dijkstra[convert(original[i])][convert(changed[i])],static_cast<long long>(cost[i]));
        }
        for(int k=0;k<26;++k)
        {
            for(int i=0;i<26;++i)
            {
                for(int j=0;j<26;++j)
                {
                    if(dijkstra[i][k]==1e15||dijkstra[k][j]==1e15)
                    {
                        continue;
                    }
                    dijkstra[i][j]=min(dijkstra[i][j],dijkstra[i][k]+dijkstra[k][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            long long diff=dijkstra[convert(source[i])][convert(target[i])];
            if(diff==1e15)
            {
                return -1;
            }
            ans+=diff;
        }
        return ans;
    }
};