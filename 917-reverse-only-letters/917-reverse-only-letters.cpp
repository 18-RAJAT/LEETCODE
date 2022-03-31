class Solution {
public:
    
    string reverseOnlyLetters(string s) {
        
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end)
        {
            while(start < end and !isalpha(s[start]))
            {
                start++;
            }
            
            while(start < end and !isalpha(s[end]))
            {
                end--;
            }
            
            swap(s[start++],s[end--]);
        }
        return s;
    }
};