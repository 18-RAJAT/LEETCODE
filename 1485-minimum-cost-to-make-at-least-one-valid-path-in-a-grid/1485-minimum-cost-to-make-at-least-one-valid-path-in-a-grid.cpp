class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>cost(n,vector<int>(m,1e9));
        cost[0][0]=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int dr[4]={-1,0,1,0},dc[4]={0,1,0,-1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int check=it.first,f=it.second.first,s=it.second.second;
            for(int i=0;i<4;++i)
            {
                int row=f+dr[i],col=s+dc[i];
                if(row>=0 && row<n && col>=0 && col<m)
                {
                    if(grid[f][s]==1 && row==f && col==s+1)
                    {
                        if(check<cost[row][col])
                        {
                            cost[row][col]=check;
                            pq.push({check,{row,col}});
                        }
                    }
                    if(grid[f][s]==2 && row==f && col==s-1)
                    {
                        if(check<cost[row][col])
                        {
                            cost[row][col]=check;
                            pq.push({check,{row,col}});
                        }
                    }
                    if(grid[f][s]==3 && row==f+1 && col==s)
                    {
                        if(check<cost[row][col])
                        {
                            cost[row][col]=check;
                            pq.push({check,{row,col}});
                        }
                    }
                    if(grid[f][s]==4 && row==f-1 && col==s)
                    {
                        if(check<cost[row][col])
                        {
                            cost[row][col]=check;
                            pq.push({check,{row,col}});
                        }
                    }
                    else if(check+1<cost[row][col])
                    {
                        cost[row][col]=check+1;
                        pq.push({check+1,{row,col}});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};