class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        queue<int>q;
        vector<int>vis(n,0);
        for(auto& it:initialBoxes)
        {
            if(status[it])q.push(it);
            else vis[it]=1;
        }
        int ans=0;
        while(!q.empty())
        {
            int F=q.front();
            q.pop();
            ans+=candies[F];
            for(auto& it:keys[F])
            {
                if(!status[it] && vis[it])
                {
                    q.push(it);
                }
                status[it]=1;
            }
            for(auto& it:containedBoxes[F])
            {
                if(status[it])q.push(it);
                else vis[it]=1;
            }
        }
        return ans;
    }
};