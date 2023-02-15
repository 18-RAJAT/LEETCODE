class Solution {
public:
    int twoEggDrop(int n) {
        int cnt=0;
        int i=1;
        int sum=0;
        while(sum<n)
        {
            sum+=i;
            ++i;++cnt;
        }
        return cnt;
    }
};