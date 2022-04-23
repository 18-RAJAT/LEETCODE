class Solution {
public:
    bool isPalindrome(int x) {
        
        
        long sum = 0, temp=x;
        
		while (x>0)
        {                  
			sum *= 10;
            
			sum+=x % 10;
			
            x /= 10;
        }
        return(sum == temp);           
        
    }
};