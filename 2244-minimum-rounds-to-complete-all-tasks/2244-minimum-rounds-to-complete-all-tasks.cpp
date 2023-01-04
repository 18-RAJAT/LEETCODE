class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        int ans=0;
        map<int,int>mp;
        for(auto &it:tasks)
        {
            mp[it]++;
        }
        vector<int>a;
        for(auto &it:mp)
        {
            a.push_back(it.second);
        }
        for(int i=0;i<a.size();++i)
        {
            if(a[i]==1)
            {
                return -1;
            }
            if(a[i]%3==0)
            {
                ans+=a[i]/3;
            }
            else
            {
                ans+=a[i]/3;
                ans++;
            }
        }
        return ans; 
    }
};