class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n=minutesToTest/minutesToDie+1;
        int ans=0;
        while(pow(n,ans)<buckets)
        {
            ans++;
        }
        return ans;
    }
};