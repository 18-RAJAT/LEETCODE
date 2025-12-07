class Solution {
public:
    int ans;
    int countOdds(int l,int h) {
        if(l%2==0)
        {
            l++;
        }
        if(h%2==0)
        {
            h--;
        }
        if(l<=h)
        {
            ans=((h-l)/2)+1;
        }
        return ans;
    }
};