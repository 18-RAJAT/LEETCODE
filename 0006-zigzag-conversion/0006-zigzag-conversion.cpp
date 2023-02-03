class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        bool down=true;
        string str[numRows];
        int row=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            str[row].push_back(s[i]);
            
            if(row==numRows-1)
            {
                down=false;
            }
            else if(row==0)
            {
                down=true;
            }
            if(down)
            {
                row++;
            }
            else
            {
                row--;
            }
        }
        string res="";
        for(int i=0;i<numRows;++i)
        {
            res+=str[i];
        }
        return res;
    }
};