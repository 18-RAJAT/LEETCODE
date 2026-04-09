class Solution{
public:
    const int mod=1e9+7;
    long long power(long long base,long long exp)
    {
        long long res=1;
        while(exp>0)
        {
            if(exp&1)res=(res*base)%mod;
            base=(base*base)%mod;
            exp>>=1;
        }
        return res;
    }
    long long modInv(long long n)
    {
        return power(n,mod-2);
    }
    int xorAfterQueries(vector<int>&nums,vector<vector<int>>&queries){
        int n=nums.size(),sq=sqrt(n);
        unordered_map<int,vector<vector<int>>>mp;
        for(auto& it:queries)
        {
            int l=it[0],r=it[1],k=it[2],v=it[3];
            if(k>=sq)
            {
                for(int i=l;i<=r;i+=k)nums[i]=(1LL*nums[i]*v)%mod;
            }
            else
            {
                mp[k].push_back(it);
            }
        }
        for(auto& it:mp)
        {
            int k=it.first;
            auto& l=it.second;
            vector<long long>diff(n,1);
            for(auto& it:l)
            {
                int l=it[0],r=it[1],v=it[3];
                diff[l]=(diff[l]*v)%mod;
                int steps=(r-l)/k;
                int nxt=l+(steps+1)*k;
                if(nxt<n)diff[nxt]=(diff[nxt]*modInv(v))%mod;
            }
            for(int i=0;i<n;++i)
            {
                if(i>=k)diff[i]=(diff[i]*diff[i-k])%mod;
                nums[i]=(1LL*nums[i]*diff[i])%mod;
            }
        }
        int ans=0;
        for(auto& it:nums)ans^=it;
        return ans;
    }
};