class Solution {
public:
    int addDigits(int num) {
        auto digitSum=[&](int dig)->int
        {
            int sum=0;
            while(dig)
            {
                sum+=dig%10;
                dig/=10;
            }
            return sum;
        };
        while(num>9)
        {
            num=digitSum(num);
        }
        return num;
    }
};