class Solution {
public:
    int countOrders(int n) {
        
        long result = 1, mod = 1000000007;
        
        for(int i = 1; i <=n; ++i)
        {
			
            result *= i;
            
            
			// Avoid OVERFLOW
            result %= mod;
			
            result *= (2*i-1);
			
		    //Again Avoid OVERFLOW
            result %= mod;
        }
        
		   
        return result % mod;
        
    }
};