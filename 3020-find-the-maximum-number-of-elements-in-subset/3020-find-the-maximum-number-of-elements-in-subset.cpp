class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mp;
        for(auto& it:nums)mp[it]++;
        int ans=1;
        if(mp.count(1))
        {
            int ones=mp[1];
            ans=max(ans,ones%2==0?ones-1:ones);
        }
        for(auto& it:mp)
        {
            int tmp=it.first,i,len=1;
            if(tmp==1)continue;
            for(i=tmp;;++len)
            {
                int root=sqrt(i);
                if(root*root!=i || !mp.count(root) || mp[root]<=1)break;
                i=root;
            }
            ans=max(ans,len*2-1);
        }
        return ans;
    }
};