class Solution {
public:
    int mirrorDistance(int n) {
        int check=0,temp=n;
        while(temp>0)
        {
            check=check*10+(temp%10);
            temp/=10;
        }
        return abs(n-check);
    }
};