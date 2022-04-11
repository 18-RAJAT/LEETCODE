class Solution {
public:
    void reverseString(vector<char>& s) {
        
       int right = s.size()-1;
        int left = 0;
        
        while(left < right)
        {
            int temp = s[left];
            
            s[left] = s[right];
            
            s[right] = temp;
            
            left = left + 1;
            right = right - 1;
        }
    }
};