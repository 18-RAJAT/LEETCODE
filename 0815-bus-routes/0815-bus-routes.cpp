class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        if(source==target)
        {
            return 0;
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();++i)
        {
            for(int j=0;j<routes[i].size();++j)
            {
                mp[routes[i][j]].push_back(i);
            }
        }
        vector<bool>visited(routes.size(),false);
        queue<int>q;
        q.push(source);
        int res=0;
        while(!q.empty())
        {
            int size=q.size();
            res++;
            for(int i=0;i<size;++i)
            {
                int cur=q.front();
                q.pop();
                for(auto bus:mp[cur])
                {
                    if(visited[bus])
                    {
                        continue;
                    }
                    visited[bus]=true;
                    for(auto stop:routes[bus])
                    {
                        if(stop==target)
                        {
                            return res;
                        }
                        q.push(stop);
                    }
                }
            }
        }
        return -1;
    }
};