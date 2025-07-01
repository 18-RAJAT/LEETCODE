class Solution {
public:
    int find(int node,vector<int>& par)
    {
        if(par[node]==node)return node;
        return par[node]=find(par[node],par);
    }
    int Union(int u,int v,vector<int>& par,vector<int>& size)
    {
        int x=find(u,par),y=find(v,par);
        if(x==y)return 0;
        if(size[x]<size[y])
        {
            par[x]=y;
            size[y]+=size[x];
        }
        else
        {
            par[y]=x;
            size[x]+=size[y];
        }
        return 1;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>par(n);
        iota(par.begin(),par.end(),0LL);
        map<string,int>MailToNode;
        vector<int>size(n,0);
        for(int i=0;i<accounts.size();++i)
        {
            for(int j=1;j<accounts[i].size();++j)
            {
                string& mail=accounts[i][j];
                auto it=MailToNode.find(mail);
                if(it==MailToNode.end())MailToNode[mail]=i;
                else Union(i,it->second,par,size);
            }
        }
        map<int,vector<string>>mailNode;
        vector<vector<string>>ans;
        for(auto& it:MailToNode)
        {
            auto ok=find(it.second,par);
            mailNode[ok].push_back(it.first);
        }
        for(auto& it:mailNode)
        {
            vector<string>res;
            sort(it.second.begin(),it.second.end());
            //add name at front....
            it.second.insert(it.second.begin(),accounts[it.first][0]);
            ans.push_back(it.second);
        }
        return ans;
    }
};