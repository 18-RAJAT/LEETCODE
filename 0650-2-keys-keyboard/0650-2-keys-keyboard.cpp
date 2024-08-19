class Solution {
public:
    int minSteps(int n) {
        int res=0,tmp=n;
        while(tmp/=2)
        {
            while(n%tmp)tmp--;
            res+=n/tmp;
            n=tmp;
        }
        return res;
    }
};