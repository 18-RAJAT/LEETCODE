class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>zc(n,0);
        for(int i=0;i<n;++i)
        {
            for(int j=n-1;j>=1 && grid[i][j]==0;--j)
            {
                zc[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int j=i;
            while(j<n && zc[j]<n-i-1)j++;
            if(j==n)return -1;
            ans+=j-i;
            while(i<j)
            {
                swap(zc[j],zc[j-1]);
                j--;
            }
        }
        return ans;
    }
};