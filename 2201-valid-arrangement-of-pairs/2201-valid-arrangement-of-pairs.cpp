class Solution{
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs){
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>In,Out;
        for(auto& pair:pairs)
        {
            adj[pair[0]].push_back(pair[1]);
            Out[pair[0]]++;
            In[pair[1]]++;
        }
        int init=pairs[0][0];
        for(auto& pair:pairs)
        {
            if(Out[pair[0]]-In[pair[0]]==1)
            {
                init=pair[0];
            }
        }
        vector<int>path;
        stack<int>stk;
        stk.push(init);
        while(!stk.empty())
        {
            int Tp=stk.top();
            if(!adj[Tp].empty())
            {
                int next=adj[Tp].back();
                adj[Tp].pop_back();
                stk.push(next);
            }
            else
            {
                path.push_back(Tp);
                stk.pop();
            }
        }
        reverse(path.begin(),path.end());
        vector<vector<int>>Ans;
        for(int i=1;i<path.size();++i)
        {
            Ans.push_back({path[i-1],path[i]});
        }
        return Ans;
    }
};