class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bit=__builtin_popcount(num2),ans=0;
        for(int i=31;~i;--i)
        {
            int mask=1<<i;
            if(mask&num1)
            {
                ans+=(1<<i),bit--;
                if(bit==0)break;
            }
        }
        if(bit==0)return ans;
        for(int i=0;i<31;++i)
        {
            int mask=1<<i;
            if(mask&ans)continue;
            else
            {
                ans+=mask,bit--;
                if(bit==0)break;
            }
        }
        return ans;
    }
};