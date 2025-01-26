//Template st=ee-ccc
struct E
{
    int t,p;
    string tp,d;
};
struct C
{
    bool operator()(const E& a,const E& b)const
    {
        if(a.t!=b.t)return a.t>b.t;
        return a.p>b.p;
    }
};
class Solution {
public:
    vector<int> countMentions(int n,vector<vector<string>>&ev) {
        priority_queue<E,vector<E>,C>pq;
        for(auto& e:ev)
        {
            E x;
            x.t=stoi(e[1]);
            if(e[0]=="ONLINE")
            {
                x.tp="ONLINE",x.p=0,x.d=e[2];
            }
            else if(e[0]=="OFFLINE")
            {
                x.tp="OFFLINE",x.p=1,x.d=e[2];
            }
            else if(e[0]=="MESSAGE")
            {
                x.tp="MESSAGE",x.p=2,x.d=e[2];
            }
            pq.push(x);
        }
        vector<bool>on(n,1);
        vector<int>res(n,0);
        while(!pq.empty())
        {
            E c=pq.top();
            pq.pop();
            if(c.tp=="ONLINE")
            {
                int u=stoi(c.d);
                on[u]=1;
            }
            else if(c.tp=="OFFLINE")
            {
                int u=stoi(c.d);
                on[u]=0;
                E x;
                x.t=c.t+60;
                x.tp="ONLINE";
                x.p=0;
                x.d=c.d;
                pq.push(x);
            }
            else if(c.tp=="MESSAGE")
            {
                string s=c.d;
                stringstream ss(s);
                string t;
                while(ss>>t)
                {
                    if(t=="ALL")
                    {
                        for(int i=0;i<n;++i)res[i]++;
                    }
                    else if(t=="HERE")
                    {
                        for(int i=0;i<n;++i)
                        {
                            if(on[i])res[i]++;
                        }
                    }
                    else
                    {
                        if(t.size()>=3 && t.substr(0,2)=="id")
                        {
                            string ok=t.substr(2);
                            int u=stoi(ok);
                            if(u>=0 && u<n)res[u]++;
                        }
                    }
                }
            }
        }
        return res;
    }
};