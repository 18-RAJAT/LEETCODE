class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>dist1(n+1,INT_MAX);
        vector<int>dist2(n+1,INT_MAX);
        vector<vector<int>>graph(n+1);
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>>q;
        dist1[1]=0;
        q.push({0,1});
        while(!q.empty())
        {
            int FF=q.front().first;
            int FS=q.front().second;
            q.pop();
            for(auto& it:graph[FS])
            {
                int reach=FF/change;
                int check=FF+time;
                if(reach%2)check=change*(1+reach)+time;
                if(dist1[it]>check)
                {
                    dist2[it]=dist1[it];
                    dist1[it]=check;
                    q.push({check,it});
                }
                else if(check>dist1[it] && check<dist2[it])
                {
                    dist2[it]=check;
                    q.push({check,it});
                }
            }
        }
        return dist2[n];
    }
};