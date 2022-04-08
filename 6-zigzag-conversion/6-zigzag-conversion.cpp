class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
        {
            return s;
        }
        
        string result;
        int n = s.size();
        
        int Cycle_Length  = 2 * numRows - 2;
        
        for(int i=0;i<numRows;++i)
        {
            for(int j=0;j+i<n;j+=Cycle_Length)
            {
                result += s[j+i];
                
                if(i != 0 and i != numRows -1 and j + Cycle_Length - i < n)
                {
                    result += s[j+Cycle_Length - i];
                }
            }
        }
        
        return result;
        
    }
};