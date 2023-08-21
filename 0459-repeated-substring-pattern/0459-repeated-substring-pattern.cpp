class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
            {
                string temp=s.substr(0,i);
                string ans="";
                for(int j=0;j<n/i;j++)
                {
                    ans+=temp;
                }
                if(ans==s)
                {
                    return true;
                }
            }
        }
        return false;      
    }
};