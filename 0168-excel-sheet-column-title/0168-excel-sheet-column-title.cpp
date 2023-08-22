class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0)
        {
            int find=columnNumber%26;
            if(find==0)
            {
                ans+='Z';
                columnNumber=columnNumber/26-1;
            }
            else
            {
                ans+=find-1+'A';
                columnNumber=columnNumber/26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};