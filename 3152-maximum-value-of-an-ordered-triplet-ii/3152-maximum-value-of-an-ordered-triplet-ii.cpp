class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0LL,mx=0LL,dif=0LL;
        for(auto& it:nums)
        {
            ans=max<long long>(ans,dif*it);
            mx=it<mx?mx:it;
            dif=(mx-it)<dif?dif:(mx-it);
        }
        return ans;
    }
};