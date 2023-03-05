class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        {
            return 0;
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int ans=0;
        while(not q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int curr=q.front();
                q.pop();
                if(curr==n-1)
                {
                    return ans;
                }
                if(curr-1>=0 and not vis[curr-1])
                {
                    q.push(curr-1);
                    vis[curr-1]=true;
                }
                if(curr+1<n and not vis[curr+1])
                {
                    q.push(curr+1);
                    vis[curr+1]=true;
                }
                for(auto it:mp[arr[curr]])
                {
                    if(not vis[it])
                    {
                        q.push(it);
                        vis[it]=true;
                    }
                }
                mp[arr[curr]].clear();
            }
            ans++;
        }
        return ans;
    }
};