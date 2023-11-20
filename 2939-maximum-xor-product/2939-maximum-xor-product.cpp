class Solution {
public:
    long long countMOD(long long x,long long y)
    {
        return (x%y);
    }
    long long left_shift(long long x,long long y)
    {
        return (x<<y);
    }
    long long right_shift(long long x,long long y)
    {
        return (x>>y);
    }
    long long bitwise_and(long long x,long long y)
    {
        return (x&y);
    }
    long long bitwise_or(long long x,long long y)
    {
        return (x|y);
    }
    long long bitwise_xor(long long x,long long y)
    {
        return (x^y);
    }
    long long bitwise_not(long long x)
    {
        return (~x);
    }
    long long bitwise_and_not(long long x,long long y)
    {
        return (x&(~y));
    }
    long long bitwise_or_not(long long x,long long y)
    {
        return (x|(~y));
    }
    long long bitwise_xor_not(long long x,long long y)
    {
        return (x^(~y));
    }
    long long bitwise_not_and(long long x,long long y)
    {
        return ((~x)&y);
    }
    long long bitwise_not_or(long long x,long long y)
    {
        return ((~x)|y);
    }
    long long bitwise_not_xor(long long x,long long y)
    {
        return ((~x)^y);
    }
    int maximumXorProduct(long long a, long long b, int n) {
        vector<long long>ar,diff;
        for(int i=0;i<n;++i)
        {
            long long checkA=(right_shift(a,i))&1;
            long long checkB=(right_shift(b,i))&1;
            
            if(bitwise_xor(checkA,checkB))
            {
                diff.push_back(i);
            }
            else
            {
                ar.push_back(i);
            }
            long long tmp=left_shift(1ll,i);
            a&=bitwise_not(tmp);
            b&=bitwise_not(tmp);
            // if(a&tmp)
            // {
            //     a=bitwise_not_and(a,tmp);
            // }
            // if(b&tmp)
            // {
            //     b=bitwise_not_and(b,tmp);
            // }
        }
        for(auto& it:ar)
        {
            a|=left_shift(1LL,it);//take/not take
            b|=left_shift(1LL,it);//vice - versa
        }
        if(a<b)
        {
            swap(a,b);
        }//0,7=12 but 10 then....
        /*
            APPROACH:
            1. If a>b then we can make all bits of a equal to 1 and all bits of b equal to 0.
            2. If a<b then we can make all bits of a equal to 1 and all bits of b equal to 0 except the last bit of a and the last bit of b.
            3. If a==b then we can make all bits of a equal to 1 and all bits of b equal to 0.
            and then we can make all bits of a equal to 1 and all bits of b equal to 0 except the last bit of a and the last bit of b.
        */
        if(diff.size()>=1)// || bitwise_not(diff.size()))
        {
            if(a>b)
            {
                for(int i=0;i<diff.size();++i)
                {
                    b|=left_shift(1,diff[i]);//vice-versa
                }
            }
            else
            {
                a|=left_shift(1LL,diff[diff.size()-1]);
                for(int i=0;i<diff.size()-1;++i)
                {
                    b|=left_shift(1LL,diff[i]);//for bit 1 in a and 0 in b
                }
            }
        }
        
        // assert(bitwise_and(a,b)==0 && bitwise_or(a,b)==(left_shift(1LL,n)-1));
        
        //check all valid
        assert(diff.size()<=n && diff.size()>=0);
        
        a=countMOD(a,1000000007);
        b=countMOD(b,1000000007);
        // cout<<"A "<<a<<"\n";
        // cout<<"B "<<b<<"\n";
        a*=b%1000000007;
        // cout<<"A "<<a<<"\n";//less<
        a=countMOD(a,1000000007);
        b=countMOD(b,1000000007);
        return a%1000000007;
    }
};