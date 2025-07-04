class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n=operations.size(),ans=0;
        k--;
        for(int i=63;~i;--i)
        {
            if(k&(1LL<<i))
            {
                if(i<n && operations[i]==1)ans=(ans+1)%26;
            }
        }
        return 'a'+ans;
    }
};