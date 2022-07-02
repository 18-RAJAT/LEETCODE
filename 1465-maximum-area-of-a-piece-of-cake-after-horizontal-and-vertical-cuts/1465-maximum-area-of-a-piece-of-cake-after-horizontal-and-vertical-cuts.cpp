#define mod 1000000007
typedef vector<int> VI;
#define fl(a,b) for(int i=a;i<b;i++)

class Solution {
public:
    int helper(int n,VI ct)
    {
        int a=ct.size();
        int b=ct[0];
        //track the maximum diff between two consecutive cuts
        fl(1,a){b=max(b,ct[i]-ct[i-1]);}
        //cout<<"h1";
        b=max(b,n-ct[a-1]);
        return b; 
    }
int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
    
        long long bre=helper(h,hc);
        long long len=helper(w,vc);
        // cout<<"2*2";
        return(len*bre)%mod;
    }
};