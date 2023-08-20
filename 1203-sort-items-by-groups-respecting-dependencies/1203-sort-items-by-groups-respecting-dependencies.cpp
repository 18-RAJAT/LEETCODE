class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before)   
    {
        vector<vector<int> > adjV(n),adjG(m),grp(m);
        vector<int> inDegV(n,0), inDegG(m,0);
        int sz=before.size();
        for(int i=0;i<sz;i++)
        {
            if(group[i]!=-1)
            {
                grp[group[i]].push_back(i);
            }
            for(auto it: before[i])
            {
                adjV[it].push_back(i);
                inDegV[i]++;
                if(group[it]!=-1 && group[i]!=-1 && group[it]!=group[i])
                {
                    inDegG[group[i]]++;
                    adjG[group[it]].push_back(group[i]);
                }
            }
        }
        //Toposort for groups
        vector<bool>visG(m,false);
        queue<int>q;
        for(int i=0;i<m;i++)
        {
            if(inDegG[i]==0)q.push(i);
        }
        vector<int>groupOrder;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            groupOrder.push_back(node);
            visG[node]=true;
            for(auto itr: adjG[node])
            {
                if(!visG[itr])
                {
                    inDegG[itr]--;
                    if(inDegG[itr]==0)
                    {
                        q.push(itr);
                    }
                }
            }
        }
        if(groupOrder.size()<m)return {};
        vector<bool>visV(n,false);
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(inDegV[i]==0&&group[i]==-1){
                q.push(i);
                cnt++;
            }
        }
        // cout<<cnt<<endl;
        for(int i=0;i<m;i++)
        {
            int grpNo=groupOrder[i];
            for(auto it: grp[grpNo])
            {
                if(inDegV[it]==0)
                {
                    q.push(it);
                }
            }
            cnt+=grp[grpNo].size();
            // cout<<cnt<<endl;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                ans.push_back(node);
                visV[node]=true;
                for(auto itr: adjV[node])
                {
                    if(!visV[itr])
                    {
                        inDegV[itr]--;
                        if(inDegV[itr]==0&&group[itr]==grpNo)
                        {
                            q.push(itr);
                        }
                    }
                }
            }
            if(ans.size()<cnt)return {};
        }
        for(int i=0;i<n;i++)
        {
            if(visV[i]==false)ans.push_back(i);
        }
        return ans;
    }
};