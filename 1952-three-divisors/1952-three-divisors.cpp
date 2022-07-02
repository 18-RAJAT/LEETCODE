#define f(a,b) for(int i=a;i<b;i++)
#define g __gcd(nums[0],nums[n-1])

class Solution {
public:
    bool isThree(int n) {
        int ct=0;
        f(2,n){if(n%i==0){ct++;}}
        if(ct==1)return true;
        else return false;
    }
};