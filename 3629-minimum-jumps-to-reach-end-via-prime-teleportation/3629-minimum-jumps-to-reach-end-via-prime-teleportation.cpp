class Solution{
public:
    int minJumps(vector<int>&nums){
        int n=nums.size(),mx=*max_element(nums.begin(),nums.end());
        vector<int>spf(mx+1);
        iota(spf.begin(),spf.end(),0);
        for(int i=2;i*i<=mx;++i)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<=mx;j+=i)if(spf[j]==j)spf[j]=i;
            }
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i)
        {
            int val=nums[i];
            while(val>=2)
            {
                int p=spf[val];
                mp[p].push_back(i);
                while(val%p==0)val/=p;
            }
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        unordered_set<int>chk;
        chk.insert(0);
        unordered_set<int>st;
        while(!q.empty())
        {
            auto [curr,dist]=q.front();
            q.pop();
            if(curr==n-1)return dist;
            for(auto& it:vector<int>{curr-1,curr+1})
            {
                if(it>=0 && it<n && chk.find(it)==chk.end())
                {
                    chk.insert(it);
                    q.push({it,dist+1});
                }
            }
            int val=nums[curr];
            if(val>1 && spf[val]==val && st.find(val)==st.end())
            {
                for(auto& it:mp[val])
                {
                    if(chk.find(it)==chk.end())
                    {
                        chk.insert(it);
                        q.push({it,dist+1});
                    }
                }
                st.insert(val);
            }
        }
        return -1;
    }
};