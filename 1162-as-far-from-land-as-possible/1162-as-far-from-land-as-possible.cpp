class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        auto cmp=[](pair<int,int>a,pair<int,int>b)
        {
            return a.first>b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
        int n=grid.size();
        // int m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                //chk with 1,then 0 and agian this process<<<<<----
                if(grid[i][j]==1)
                {
                    pq.push(make_pair(0,i*n+j));
                }
            }
        }
        //sz=NxN grid or chk with the sz
        //base case
        if(pq.size()==n*n or pq.size()==0)
        {
            return -1;
        }
        int ans=0;
        //assumption
        while(not pq.empty())
        {
            pair<int,int>pr=pq.top();pq.pop();
            int sc1=pr.second/n;//1
            int sc2=pr.second%n;//2
            
            ans=max(ans,pr.first);
            //dist1->assumption
            if(sc1-1>=0 and grid[sc1-1][sc2]==0)
            {
                grid[sc1-1][sc2]=1;
                pq.push(make_pair(pr.first+1,(sc1-1)*n+sc2));
                // cout<<sc1<<"->"<<sc2<<"\n";
            }
            //dist2->assumption
            if(sc1+1<n and grid[sc1+1][sc2]==0)
            {
                grid[sc1+1][sc2]=1;
                pq.push(make_pair(pr.first+1,(sc1+1)*n+sc2));
                // cout<<sc1<<"->"<<sc2<<"\n";
            }
            //dist3->assumption
            if((sc2-1)>=0 and grid[sc1][sc2-1]==0)
            {
                grid[sc1][sc2-1]=1;
                pq.push(make_pair(pr.first+1,sc1*n+sc2-1));
                // cout<<sc1<<"->"<<sc2<<"\n";
            }
            //dist4->assumption
            if(sc2+1<n and grid[sc1][sc2+1]==0)
            {
                grid[sc1][sc2+1]=1;
                pq.push(make_pair(pr.first+1,sc1*n+sc2+1));
                // cout<<sc1<<"->"<<sc2<<"\n";
            }
        }
        return ans;
    }
};