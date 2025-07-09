class Solution {
public:
    int maxFreeTime(int t, int k, vector<int>& s, vector<int>& e) {
        int n=s.size(),g=0;
        g=max(g,s[0]),g=max(g,t-e[n-1]);
        for(int i=0;i+1<n;++i)g=max(g,s[i+1]-e[i]);
        vector<int>p(n+1,0);
        for(int i=0;i<n;++i)p[i+1]=p[i]+(e[i]-s[i]);
        auto ef=[&](int i){return i<0?0:e[i];};
        auto sf=[&](int i){return i>=n?t:s[i];};
        int ans=g,i=0;
        for(int j=0;j<n;++j)
        {
            while(j-i+1>k)i++;
            int l=ef(i-1),r=sf(j+1),d=p[j+1]-p[i],a=r-l;
            if(d<=a)ans=max(ans,a-d);
        }
        return ans;
    }
};