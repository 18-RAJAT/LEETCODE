class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        int n=s.length();
        string ans="";
        int gap=2*numRows-2;
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<n;j+=gap)
            {
                ans+=s[j];
                if(i!=0 and i!=numRows-1 and j+gap-2*i<n)
                {
                    ans+=s[j+gap-2*i];
                }
            }
        }
        return ans;
    }
};