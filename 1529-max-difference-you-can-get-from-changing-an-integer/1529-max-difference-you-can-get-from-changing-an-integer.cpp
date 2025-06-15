class Solution {
public:
    int maxDiff(int num) {
        int ok=num;
        int ar[10]={0};
        for(int t=1;ok;t*=10)
        {
            ar[ok%10]+=t;
            ok/=10;
        }
        int tp=num;
        while(tp>=10)
        {
            tp/=10;
        }
        int m1=INT_MIN,m2=INT_MAX;
        for(int i=0;i<=9;++i)
        {
            m1=max(m1,num+(9-i)*ar[i]);
            if(i==tp)
            {
                m2=min(m2,num-(i-1)*ar[i]);
            }
            else
            {
                m2=min(m2,num-i*ar[i]);
            }
        }
        return m1-m2;
    }
};