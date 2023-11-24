class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int ans=0;
        for(int i=n/3;i<n;i+=2)//n/3 is the number of piles that can be taken by me,i+=2 is second maxi
        {
            ans+=piles[i];
        }
        return ans;
    }
};