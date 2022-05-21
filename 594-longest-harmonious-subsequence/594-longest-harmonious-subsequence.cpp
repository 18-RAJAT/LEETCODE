class Solution {
public:
    int findLHS(vector<int>& n) {

            map<int,int>mp;
            int result=0;
            for(int i=0;i<n.size();++i)
            {
              mp[n[i]]++;
                    if(mp.find(n[i]-1)!=mp.end())
                    {
                            result=max(result,mp[n[i]-1]+mp[n[i]]);
                    }
                    if(mp.find(n[i]+1)!=mp.end())
                    {
                            result=max(result,mp[n[i]+1]+mp[n[i]]);
                    }
            }
            return result;
    }
};
