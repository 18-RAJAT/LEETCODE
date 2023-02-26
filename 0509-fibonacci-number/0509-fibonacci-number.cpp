class Solution {
public:
    int fib(int n) {
        function<int(int)>fib=[&](int n)->int
        {
            if(n==0 or n==1)
            {
                return n;
            }
            return fib(n-1)+fib(n-2);
        };
        return fib(n);
    }
};