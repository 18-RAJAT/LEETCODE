class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        vector<int>left;
        left.assign(n+1,0);
        vector<int>right;
        right.assign(n+1,0);
        left[0]=(s[0]=='1')?2:0;
        int ans=n;
        for(int i=1;i<n;++i)
        {
            left[i]=min(left[i-1],i);
            if(s[i]=='1')
            {
                left[i]+=2;
            }
        }
        for(int i=n-1;~i;--i)
        {
            right[i]=min(right[i+1],n-(i+1));
            if(s[i]=='1')
            {
                right[i]+=2;
            }
            int current=min(left[i],i);
            current+=min(right[i],n-i);
            ans=min(ans,current);
        }
        ans=min(ans,right[0]);
        return ans;
    }
};