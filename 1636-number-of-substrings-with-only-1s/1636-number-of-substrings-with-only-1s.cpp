class Solution {
public:
    const int Mod=1000000007;
    int numSub(string s) {
        long long res=0,ans=0;
        for(auto& it:s)
        {
            if(it=='1')
            {
                ans=(ans+res+1)%Mod,res++;
            }
            else res=0;
        }
        return ans;
    }
};