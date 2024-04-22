class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        set<string>dead;
        auto check="0000";
        for(int i=0;i<n;++i)
        {
            dead.insert(deadends[i]);
        }
        if(dead.find(check)!=dead.end())return -1;
        if(target==check)return 0;
        queue<string>q;
        q.push(check);
        int ans=0;
        set<string>visited;
        visited.insert(check);
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
                    if(visited.find(temp)==visited.end()&&dead.find(temp)==dead.end())
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                    temp=cur;
                    temp[j]=(temp[j]-'0'-1+10)%10+'0';
                    if(visited.find(temp)==visited.end()&&dead.find(temp)==dead.end())
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};