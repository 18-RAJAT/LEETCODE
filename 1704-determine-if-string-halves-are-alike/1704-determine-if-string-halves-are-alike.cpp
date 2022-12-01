class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int ct=0;
        vector<char>a{'a','e','i','o','u','A','E','I','O','U'};
        
        for(int i=0;i<n;++i)
        {
            if(i<n/2)
            {
                if(find(a.begin(),a.end(),s[i])!=a.end())
                {
                    ct++;
                }
            }
            else
            {
                if(find(a.begin(),a.end(),s[i])!=a.end())
                {
                    ct--;
                }
            }
        }
        if(ct)return false;
        else return true;
    }
};