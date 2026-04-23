class Solution{
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i)mp[nums[i]].push_back(i);
        vector<long long>ans(n,0);
        for(auto& it:mp)
        {
            vector<int>& chk=it.second;
            int k=chk.size();
            vector<long long>ar(k);
            ar[0]=chk[0];
            for(int i=1;i<k;++i)ar[i]=ar[i-1]+chk[i];
            for(int i=0;i<k;++i)
            {
                long long left=0,right=0;
                if(i>0)left=(long long)i*chk[i]-ar[i-1];
                if(i<k-1)right=(ar[k-1]-ar[i])-(long long)(k-i-1)*chk[i];
                ans[chk[i]]=left+right;
            }
        }
        return ans;
    }
};