class Solution {
public:
    
    bool CheckPalindrome(string s,int start,int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int left = 0;
        int right = s.size()-1;
        
        while(left <= right)
        {
            if(s[left] != s[right])
            {
                if(CheckPalindrome(s,left+1,right) or CheckPalindrome(s,left,right-1))
                {
                    return true;
                }
                
                else
                {
                    return false;
                }
            }
            
            left++;
            right--;
        }
        return true;
    }
};