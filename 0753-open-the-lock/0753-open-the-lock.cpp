class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>dead(deadends.begin(),deadends.end());
        string start="0000";
        if(dead.count(start))return -1;
        if(target==start)return 0;
        queue<string>q;
        q.push(start);
        set<string>vis;
        vis.insert(start);
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;++i)
            {
                string cur=q.front();
                q.pop();
                if(cur==target)return ans;
                for(int j=0;j<4;++j)
                {
                    string temp=cur;
                    temp[j]=(temp[j]-'0'+1)%10+'0';
                    if(!vis.count(temp) && !dead.count(temp))
                    {
                        q.push(temp);
                        vis.insert(temp);
                    }
                    temp=cur;
                    temp[j]=(temp[j]-'0'-1+10)%10+'0';
                    if(!vis.count(temp) && !dead.count(temp))
                    {
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};