class Solution {
public:
    int recur(int n)
    {
        while(n)
        {
            if((n%10)==0)return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;++i)
        {
            int l=i,r=n-i;
            if(recur(l) && recur(r))return {l,r};
        }
        return {};
    }
};