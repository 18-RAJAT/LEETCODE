class Solution {
public:
    int fib(int n) {
        
        if(n == 0 or n == 1)
        {
            return n;
        }
        
        int subproblem1 = fib(n-1);
        int subproblem2 = fib(n-2);
        
        return subproblem1 + subproblem2;
        
    }
};