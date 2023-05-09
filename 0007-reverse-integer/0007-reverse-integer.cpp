class Solution {
public:
    Solution() {}
    ~ Solution() {}    
    int reverse(int x) {
        long long int reversed =0;
        while(x!=0)
        {
            long long int digit=x%10;
            reversed=reversed*10+digit;
            x/=10;
        }
        if(reversed>INT_MAX or reversed<INT_MIN)
        {
            return 0;
        }
        return static_cast<int>(reversed);
    }
};