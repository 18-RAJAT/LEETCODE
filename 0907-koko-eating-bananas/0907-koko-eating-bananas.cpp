class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=0,r=1e9;
        //using invariant style
        while(r-l>1)
        {
            long long res=0;
            int mid=l+(r-l)/2;
            for(int i=0;i<n;++i)res+=ceil((double)piles[i]/mid);
            (res<=h)?r=mid:l=mid;
        }
        return r;
    }
};