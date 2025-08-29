class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n>=m)swap(n,m);
        long long int even=n/2,odd=(m+1)/2,ans=even*odd;
        even=m/2,odd=(n+1)/2;
        ans+=even*odd;
        return ans;
    }
};