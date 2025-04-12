class Solution {
public:
    static constexpr array<long long,11>Fact={1,1,2,6,24,120,720,5040,40320,362880,3628800};
    long long countGoodIntegers(int n,int k)
    {
        vector<long long>pali_recur;
        if(n==0)return 0;
        int sza=(n+1)/2;
        long long start=1;
        for(int i=1;i<sza;++i)
        {
            start*=10;
        }
        long long end=start*10-1;

        if(n==1)start=0;
        for(long long i=start;i<=end;++i)
        {
            long long num=i,k_pali=i;
            if(n%2!=0)k_pali/=10;
            while(k_pali>0)
            {
                num=num*10+(k_pali%10);
                k_pali/=10;
            }
            if(to_string(num).size()==n && num%k==0)
            {
                pali_recur.push_back(num);
            }
        }
        set<array<int,10>>ms;
        for(auto& it:pali_recur)
        {
            array<int,10>arr;
            arr.fill(0);
            long long k_pali=it;
            for(int i=0;i<n;++i)
            {
                arr[k_pali%10]++;
                k_pali/=10;
            }
            ms.insert(arr);
        }
        long long ans=0;
        for(const array<int,10>& Value:ms)
        {
            long long temp=0;
            for(int Good=1;Good<=9;++Good)
            {
                if(Value[Good]==0)continue;

                array<int,10>pali_good=Value;
                pali_good[Good]--;
                bool valid=true;
                for(auto& it:pali_good)
                {
                    if(it<0)
                    {
                        valid=false;
                        break;
                    }
                }
                if(!valid)continue;
                long long init=Fact[n-1];
                for(int i=0;i<=9;++i)
                {
                    init/=Fact[pali_good[i]];
                }
                temp+=init;
            }
            ans+=temp;
        }
        return ans;
    }
};