class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int lft=1,ryt=1e9;
        while(lft<ryt)
        {
            int tot=0;
            int mid=lft+(ryt-lft)/2;
            for(int i=0;i<n;++i)
            {
                tot+=ceil((double)piles[i]/mid);
            }
            if(tot<=h)
            {
                ryt=mid;
            }
            else
            {
                lft=mid+1;
            }
        }
        return lft;
    }
};