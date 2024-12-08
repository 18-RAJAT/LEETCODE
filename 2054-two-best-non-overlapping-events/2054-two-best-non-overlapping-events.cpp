class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        set<int> s;
        map<int,vector<int>>F,L;
        for(int i=0;i<events.size();++i)
        {
            s.insert(events[i][0]);
            s.insert(events[i][1]);
            F[events[i][0]].push_back(events[i][2]);
            L[events[i][1]].push_back(events[i][2]);
        }
        int res=0,ans=0;
        auto x=s.begin(),y=s.end();
        while(x!=y)
        {
            int a=*x;
            for(int i=0;i<F[a].size();++i)
            {
                ans=max(ans,res+F[a][i]);
            }
            for(int i=0;i<L[a].size();++i)
            {
                res=max(res,L[a][i]);
            }
            x++;
        }
        return ans;
    }
};