class Solution {
public:
    string makeGood(string s) {
        string result;
        int n=s.length();
        
        for(int i=0;i<n;++i)
        {
            if(abs(s[i]-s[i+1])==abs('a'-'A'))
            {
                i++;
            }
            else
            {
                result+=s[i];
            }
        }
        int m=result.size();
        if(n==m)
        {
            return result;
        }
        return makeGood(result);
    }
};