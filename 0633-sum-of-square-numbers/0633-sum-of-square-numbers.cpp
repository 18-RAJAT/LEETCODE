class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a=0,b=(long long)sqrt(c);
        while(a<=b)
        {
            long long sum=a*a+b*b;
            if(sum<c)a++;
            else if(sum>c)b--;
            else return true;
        }
        return false;
    }
};