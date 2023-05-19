class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
     int n=graph.size();
        vector<int>colors(n,0);
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(colors[i])
            {
                continue;
            }
            colors[i]=1;
            q.push(i);
            cout<<"1";
            
            while(not q.empty())
            {
                int tp=q.front();
                cout<<"2";
                for(auto a : graph[tp])
                {
                    if(not colors[a])
                    {
                        colors[a]-=colors[tp];q.push(a);
                        cout<<"3";
                    }
                    else if(colors[a]==colors[tp])
                    {
                        return false;
                    }
                }
                q.pop();
            }
        }
        return true;
    }
};