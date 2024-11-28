class Solution {
public:
    vector<pair<int,int>>valid={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dis[0][0]=0;
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int F=pq.top().first;
            int SF=pq.top().second.first;
            int SS=pq.top().second.second;
            pq.pop();
            for(auto& it:valid)
            {
                if((SF+it.first)>=0 && (SF+it.first<grid.size()) && (SS+it.second)>=0 && (SS+it.second)<grid[0].size())
                {
                    if(F+grid[SF+it.first][SS+it.second]<dis[SF+it.first][SS+it.second])
                    {
                        dis[SF+it.first][SS+it.second]=F+grid[SF+it.first][SS+it.second];
                        pq.push({dis[SF+it.first][SS+it.second],{SF+it.first,SS+it.second}});
                    }
                }
            }
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
};