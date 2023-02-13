class Solution {
public:
    bool isDigit(char c)
    {
        return(c>='0' and c<='9');
    }
    string decodeString(string s) {
        function<string(int&,int)>decode=[&](int &i,int k)
        {
            string ans="";
            int sz=s.size();
            //we will itr when the close ] is not encounter and we reach end of the string
            while(i<sz and s[i]!=']')
            {
                if(not isDigit(s[i]))
                {
                    ans+=s[i++];
                }
                else
                {
                    int n=0;
                    //now the number of times the string inside the [] will be repeated
                    while(i<sz and isDigit(s[i]))n=n*10+s[i++]-'0';
                    i++;//'['
                    string tmp=decode(i,n);
                    i++;//']'
                    
                    while(n-->0)
                    {
                        ans+=tmp;
                    }
                }
            }
            return ans;
        };
        int i=0;
        //The number of times the string inside the [] will be repeated
        return decode(i,0);
    }
};