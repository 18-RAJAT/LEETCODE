class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        int L=left,R=right;
        while(L!=R)
        {
            L>>=1;
            R>>=1;
            ans++;
        }
        return L<<ans;
    }
};