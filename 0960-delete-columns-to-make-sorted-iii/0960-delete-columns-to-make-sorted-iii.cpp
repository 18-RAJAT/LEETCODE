class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size(),ans=1;
        vector<int>lis(m,1);
        for(int i=1;i<m;++i)
        {
            for(int j=0;j<i;++j)
            {
                int ok=1;
                for(int k=0;k<n;++k)
                {
                    if(strs[k][i]<strs[k][j])
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    if(lis[i]<lis[j]+1)lis[i]=lis[j]+1;
                }
            }
            ans=max(ans,lis[i]);
        }
        return m-ans;
    }
};