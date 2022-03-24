class Solution {
public:
    string addStrings(string num1, string num2) {

        int sum = 0;
        int i = num1.length()-1;
        int j = num2.length()-1;
        
        string s;
        
        while(i >= 0 or j >= 0 or sum > 0)
        {
            if(i >= 0)
            {
                sum += (num1[i--] - '0');
            }
            
            if(j >= 0)
            {
                sum += (num2[j--] - '0');
            }
            
            s.insert(0,1,(sum % 10) + '0');
            
            sum  = sum / 10;
        }
        return s;
    }
};