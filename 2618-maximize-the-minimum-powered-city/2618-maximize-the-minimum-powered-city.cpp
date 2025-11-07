class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long>a(n+1,0);
        for(int i=0;i<n;++i)
        {
            a[max(i-r,0)]+=1ll*stations[i];
            a[min(i+r,n-1)+1]-=1ll*stations[i];
        }
        for(int i=1;i<n;++i)a[i]+=a[i-1];
        long long L=0,R=LLONG_MAX,ans=0;
        while(L<=R)
        {
            vector<long long>chk(n+1,0);
            long long mid=L+(R-L)/2,rem=k;
            for(int i=0;i<n;++i)
            {
                if(i)chk[i]+=chk[i-1];
                long long tot=a[i]+chk[i];
                if(tot<mid)
                {
                    long long ret=mid-tot;
                    rem-=ret;
                    if(rem<0)
                    {
                        break;
                    }
                    long long mn=min(i+r+r,n-1);
                    chk[i]+=ret;
                    chk[mn+1]-=ret; 
                }
            }
            if(rem>=0)
            {
                ans=mid;
                L=mid+1;
            }
            else
            {
                R=mid-1;
            }
        }
        return ans;
    }
};