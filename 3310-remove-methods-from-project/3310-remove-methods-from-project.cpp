class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>>direct,mp_sus;
        vector<int>in_ed(n,0);
        for(auto& it:invocations)
        {
            int a=it[0],b=it[1];
            direct[a].push_back(b);
            mp_sus[b].push_back(a);
            in_ed[b]++;
        }
        unordered_set<int>sus;
        queue<int>q;
        q.push(k);
        sus.insert(k);
        while(!q.empty())
        {
            int F=q.front();
            q.pop();
            for(auto& it:direct[F])
            {
                if(sus.find(it)==sus.end())
                {
                    sus.insert(it);
                    q.push(it);
                }
            }
        }
        for(auto& it1:sus)
        {
            for(auto& it2:mp_sus[it1])
            {
                if(sus.find(it2)==sus.end())
                {
                    vector<int>res(n);
                    for(int i=0;i<n;++i)res[i]=i;
                    return res;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(sus.find(i)==sus.end()) ans.push_back(i);
        }
        return ans;
    }
};