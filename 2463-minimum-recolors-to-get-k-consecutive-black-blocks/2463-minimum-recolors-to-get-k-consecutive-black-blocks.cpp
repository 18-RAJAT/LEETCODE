class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size(),w=0,ans=INT_MAX;
        for(int i=0;i<k;++i)if(blocks[i]=='W')w++;
        ans=w;
        for(int i=k;i<n;++i)
        {
            if(blocks[i-k]=='W')w--;
            if(blocks[i]=='W')w++;
            ans=min(ans,w);
        }
        return ans;
    }
};